

var generator;

var builders;

var nextUpdate = 0.0;
var increment = 1.0;
var lookAhead = 1.0;

var startingPoint = 0;
var playing = false;

var synths;

let voicesPerSynth = 5;

function setModule(module)
{
  Module = module;
}

function setTone(tone)
{
  Tone = tone;
  setSynths();
}

function setBuilders(b)
{
  builders = JSON.parse(b);
}

function setSynths()
{
  synths = [];
  synths.push(new Tone.PolySynth(voicesPerSynth, Tone.Synth).toMaster());
  synths.push(new Tone.PolySynth(voicesPerSynth, Tone.AMSynth).toMaster());
  synths.push(new Tone.PolySynth(voicesPerSynth, Tone.DuoSynth).toMaster());
  synths.push(new Tone.PolySynth(voicesPerSynth, Tone.FMSynth).toMaster());
  synths.push(new Tone.PolySynth(voicesPerSynth, Tone.MonoSynth).toMaster());
}

function save()
{
  $("#data").val(JSON.stringify(getTheme($("#root"))));
}

function load()
{
  displayTheme($("#root"), JSON.parse($("#data").val()));
}

function play()
{
  playing = !playing;
  if (playing)
  {
    console.log("playing");
    console.log(JSON.stringify(getTheme($("#root"))));
    generator = Module.getTheme(JSON.stringify(getTheme($("#root")))).getGenerator();
    startingPoint = Tone.now();
    updateTime();
    $("#play").html("Stop");
  }
  else
  {
    synths.forEach(function(synth){
      synth.releaseAll();
    });
    $("#play").html("Play");
  } 
}

function scheduleNote(channel, note, duration, timing)
{
  //console.log("Note: " + note.key + " " + duration + " at " + timing + " channel: " + channel);
  synths[channel].triggerAttackRelease(Tone.Frequency(note.key, "midi"), duration, timing);
}

function updateTime(){
  if (playing)
  {
    requestAnimationFrame(updateTime);
  }

  $("#test").text((Tone.now() - startingPoint).toFixed(3));

  if (Tone.now() >= nextUpdate)
  {
    var currentTime = Tone.now() - startingPoint;
    nextUpdate = currentTime + increment;
    var stream = generator.getNext(nextUpdate + lookAhead);
    var notes = [];

    while(stream.hasNext())
    {
      var note = stream.getNext();
      if (note.isNoteOn)
      {
        notes.push(note);
      }
      else
      {
        for (var i = 0; i < notes.length; ++i)
        {
          if (notes[i].key == note.key && notes[i].channel == note.channel)
          {
            scheduleNote (note.channel, notes[i], note.time - notes[i].time, notes[i].time + startingPoint);
            //if (note.time - notes[i].time < 2)
              //console.log(note.key);
            notes.splice(i, 1);
            break;
          }
        }
      }
    }
  }
}

function displayTheme(div, node)
{
  currentRoot = div;
  currentNode = node;
  div.empty();
  div.append(createNode(node, "Theme"));
}

function createNode(node, builderType)
{
  var toAppend = "";
  if (node.type != "None")
  {
    builder = builders[builderType][node.type];
    toAppend += "<div data-interface=\"" + builderType + "\" data-builder=\"" + node.type + "\"><h3>" + builder.display + "</h3>";
    builder.requirements.forEach(function(requirement){
      var n = undefined;
      if (node.hasOwnProperty(requirement.attribute))
      {
        n = node[requirement.attribute];
      }
      toAppend += parseRequirement(requirement, n);
    });
    toAppend += "</div>";
  }
  return toAppend;
}

function parseRequirement(requirement, node)
{
  var data = "";
  
  if (requirement.type == "int")
  {
    data += "<div data-attribute=\"" + requirement.attribute + "\" class=\"boxed simple\"><p>" + requirement.display + ": <input type=\"number\" onchange=\"updateTheme();\"";
    if (node != undefined)
    {
      data += " value=\"" + node + "\"";
    }
    else if (requirement.hasOwnProperty("default"))
    {
      data += " value=\"" + requirement.default + "\"";
    }
    data += "></p></div>";
  }
  else if (requirement.type == "map")
  {
    data += "<div data-attribute=\"" + requirement.attribute + "\" class=\"boxed map\"><h4>" + requirement.display + ":</h4>";

    if (node != undefined)
    {
      var map = node
      for (var index in map)
      {
        if (map.hasOwnProperty(index) && index)
        {
          data += "<p>Track: <input type=\"text\" placeholder=\"deleted or none\" value=\"" + index + "\"> <button type=\"button\" onclick=\"updateTheme();\">set name or delete</button></p>";
          data += createMap(requirement, map[index]);
        }
      }
    }

    if (requirement.defaultElement && (node == undefined || !node.hasOwnProperty("default")))
    {
      data += "<p>Track: Default</p>";
      data += "<p>Track: <input type=\"text\" placeholder=\"deleted or none\" value=\"default\"> <button type=\"button\" onclick=\"updateTheme();\">set name or delete</button></p>";
      var noneMap = [[]];
      data += createMap(requirement, noneMap);
    }

    data += "<p>Track: <input type=\"text\" placeholder=\"deleted or none\"> <button type=\"button\" onclick=\"updateTheme(this);\">set name or delete</button></p>";
    data += "</div>";
  }
  else if(requirement.type == "choice")
  {
    data += "<div data-attribute=\"" + requirement.attribute + "\" class=\"boxed simple\"><p>" + requirement.display + ": <select>";
    requirement.choices.forEach(function(choice)
    {
      data += "<option value=\"" + choice + "\"";
      if (node != undefined && node == choice)
      {
        data += " selected";
      }
      data += ">" + choice + "</option>";
    });
    data += "</select></p></div>";
  }
  else if (requirement.type == "array")
  {
    data += "<div data-attribute=\"" + requirement.attribute + "\" class=\"boxed map\"><p>" + requirement.display + ": <button type=\"button\" onclick=\"updateArray(this, 1)\">Add " + requirement.requirement.display + "</button><button type=\"button\" onclick=\"updateArray(this, -1)\">Remove Last " + requirement.requirement.display + "</button></p><div>";

    if (node != undefined)
    {
      node.forEach(function(selectedNode){
        data += "<div class=\"boxed-map\">" + parseRequirement(requirement.requirement, selectedNode) + "</div>";
      });
    }
    data += "</div></div>";
  }
  else
  {
    var i = 0;
    if (node != undefined)
    {
      node.forEach(function(selectedNode)
      {
        data += createSelect(requirement, selectedNode);
        i+=1;
      });
    }
    data += createSelect(requirement, {type:"None"});
  }

  return data;
}

function createMap(requirement, mapNode)
{
  var data = "";
  var i = 0;
  if (mapNode.length > 0 && mapNode[0].length > 0)
  {
    mapNode.forEach(function(selectedArray)
    {
      data += "<div class=\"boxed-map\">";
      selectedArray.forEach(function(selectedNode)
      {
        data += createSelect(requirement.requirement, selectedNode);
      });
      var noneNode = {type:"None"};
      data += createSelect(requirement.requirement, noneNode);
      data += "</div>";
      i+=1;
    });
  }
  data += "<div class=\"boxed-map\">"
  var noneNode = {type:"None"};
  data += createSelect(requirement.requirement, noneNode);
  data += "</div>";
  return data;
}

function createSelect(requirement, selectedNode)
{
  var data = "<div data-attribute=\"" + requirement.attribute + "\" class=\"boxed builder\"><p>" + requirement.display + ": <select data-builderType=\"" + requirement.type + "\" onchange=\"updateSelect(this);\"><option value=\"None\">None</option>";
  var builder = builders[requirement.type];
  for (var prop in builder)
  {
    if (builder.hasOwnProperty(prop))
    {
      data += "<option value=\"" + prop +  "\"";
      if (selectedNode.type == prop)
      {
        data += " selected";
      }
      data += ">" + builder[prop].display + "</option>";
    }
  }
  data += "</select></p>";

  if (selectedNode.type != "None")
  {
    data += createNode(selectedNode, requirement.type);
  }
  return data + "</div>";
}

function updateArray(div, amount)
{
  if (amount == -1 && $(div).parent().parent().children("div").length > 0)
  {
    $(div).parent().parent().children("div").children("div").last().remove();
  }
  else if (amount == 1)
  {
    $(div).parent().parent().children("div").append("<div></div>");
  }
  updateTheme();
}

function updateSelect(select)
{
  $(select).parent().parent().children("div").remove();
  $(select).parent().parent().append(createNode({type: $(select).val()}, $(select).attr("data-builderType")));
  updateTheme();
}

function updateTheme()
{
  displayTheme($("#root"), getTheme($('#root')));
}

function getTheme(root)
{
  return getNode(root.children("div"));
}

function getNode(div)
{
  var node = {};
  var builder = builders[div.attr("data-interface")][div.attr("data-builder")];
  node.type = div.attr("data-builder");
  builder.requirements.forEach(function(requirement)
  {
    node[requirement.attribute] = getAttribute(requirement, div.children("[data-attribute='" + requirement.attribute + "']"));
  });

  return node;
}

function getAttribute(requirement, attribute)
{
  var node;
  if (requirement.type == "int")
  {
    node = Number(attribute.children("p").children("input").val());
  }
  else if (requirement.type == "map")
  {
    var current = attribute.children().next();
    node = {};
    while (current.length > 0 && current.first().is("p"))
    {
      var key = current.first().children("input").val();
      current = current.next();
      if (key != undefined && key.length > 0)
      {
        var submap = [];
        while (current.first().is("div"))
        {
          var builderSet = [];
          current.first().children("[data-attribute='sub-attribute']").each(function()
          {
            if ($(this).children("p").children("select").val() != "None")
            {
              builderSet.push(getNode($(this).children("div")));
            }
          });
          if (builderSet.length > 0)
          {
            submap.push(builderSet);
          }
          current = current.next();
        }
        node[key] = submap;
      }
      else
      {
        while (current.first().is("div"))
        {
          current = current.next()
        }
      }
    }
  }
  else if (requirement.type == "choice")
  {
    node = attribute.children("p").children("select").val();
  }
  else if(requirement.type == "array")
  {
    node = [];
    attribute.children("div").children("div").each(function(){
      node.push(getAttribute(requirement.requirement, $(this).children("div")));
    });
  }
  else
  {
    node = [];
    attribute.each(function()
    {
      if ($(this).children("p").children("select").val() != "None")// && $(this).children("div").length > 0)
      {
        node.push(getNode($(this).children("div")));
      }
    });
  }

  return node;
}
