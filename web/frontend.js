

var generator;
var synth;
var g = true;

var builders = JSON.parse("{\"Theme\":{\"Theme\":{\"display\":\"Theme\",\"requirements\":[{\"type\":\"GeneratorBuilder\",\"attribute\":\"generator\",\"display\":\"Generator\"}]}},\"GeneratorBuilder\":{\"StructuredGeneratorBuilder\":{\"display\":\"StructuredGenerator\",\"requirements\":[{\"type\":\"int\",\"attribute\":\"minSections\",\"display\":\"MinSections\",\"default\":\"1\"},{\"type\":\"int\",\"attribute\":\"maxSections\",\"display\":\"MaxSections\",\"default\":\"3\"},{\"type\":\"NoteCollectionBuilder\",\"attribute\":\"noteCollection\",\"display\":\"NoteCollection\"}]}},\"NoteCollectionBuilder\":{\"TimelineNoteCollectionBuilder\":{\"display\":\"TimelineNoteCollection\",\"requirements\":[{\"type\":\"map\",\"attribute\":\"ingredients\",\"display\":\"Tracks\",\"defaultElement\":true,\"requirement\":{\"type\":\"IngredientBuilder\",\"display\":\"Ingredient\"}}]}},\"IngredientBuilder\":{\"ProgressionIngredientBuilder\":{\"display\":\"ProgressionIngredient\",\"requirements\":[]},\"MelodySequenceIngredientBuilder\":{\"display\":\"MelodySequenceIngredient\",\"requirements\":[]},\"HarmonySequenceIngredientBuilder\":{\"display\":\"HarmonySequenceIngredient\",\"requirements\":[]},\"CustomScaleIngredientBuilder\":{\"display\":\"CustomScaleIngredient\",\"requirements\":[]},\"ScaleIngredientBuilder\":{\"display\":\"ScaleIngredient\",\"requirements\":[{\"type\":\"choice\",\"attribute\":\"scale\",\"display\":\"Scale\",\"choices\":[\"major\",\"minor\"]}]}}}");

var currentNode;
var currentRoot;

var nextUpdate = 0.0;
var increment = 1.0;
var lookAhead = 1.0;

function setModule(module)
{
  Module = module;
}

function setTone(tone)
{
  Tone = tone;
  synth = new Tone.PolySynth(5, Tone.Synth).toMaster();
}

function play(data)
{
  console.log("Playing");
  console.log(data);
  var theme = Module.getTheme(data);
  generator = theme.getGenerator();
  console.log("Start");
  updateTime();
}

function go(root)
{
  g = false;
  console.log("Stopping");
}

function scheduleNote(note, duration)
{
  synth.triggerAttackRelease(Tone.Frequency(note.key, "midi"), duration, note.time + 1);
}

function updateTime(){
  if (g)
  {
    requestAnimationFrame(updateTime);
  }
  document.getElementById("test").innerHTML = Tone.now().toFixed(3);

  if (Tone.now() >= nextUpdate)
  {
    var currentTime = Tone.now();
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
            scheduleNote (notes[i], note.time - notes[i].time);
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
      toAppend += parseRequirement(requirement, node);
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
    data += "<div data-attribute=\"" + requirement.attribute + "\" class=\"boxed\"><p>" + requirement.display + ": <input type=\"number\" onchange=\"updateTheme();\"";
    if (node.hasOwnProperty(requirement.attribute))
    {
      data += " value=\"" + node[requirement.attribute] + "\"";
    }
    else if (requirement.hasOwnProperty("default"))
    {
      data += " value=\"" + requirement.default + "\"";
    }
    data += "></p></div>";
  }
  else if (requirement.type == "map")
  {
    data += "<div data-attribute=\"" + requirement.attribute + "\" class=\"boxed\"><h4>" + requirement.display + ":</h4>";

    if (node.hasOwnProperty(requirement.attribute))
    {
      var map = node[requirement.attribute]
      for (var index in map)
      {
        if (map.hasOwnProperty(index) && index)
        {
          data += "<p>Track: <input type\"text\" placeholder=\"deleted or none\" value=\"" + index + "\"> <button type\"button\" onclick=\"updateTheme();\">set name or delete</button></p>";
          data += createMap(requirement, map[index]);
        }
      }
    }

    if (requirement.defaultElement && (!node.hasOwnProperty(requirement.attribute) || !node[requirement.attribute].hasOwnProperty("default")))
    {
      data += "<p>Track: Default</p>";
      data += "<p>Track: <input type\"text\" placeholder=\"deleted or none\" value=\"default\"> <button type\"button\" onclick=\"updateTheme();\">set name or delete</button></p>";
      var noneMap = [[]];
      data += createMap(requirement, noneMap);
    }

    data += "<p>Track: <input type=\"text\" placeholder=\"deleted or none\"> <button type=\"button\" onclick=\"updateTheme(this);\">set name or delete</button></p>";
    data += "</div>";
  }
  else if(requirement.type == "choice")
  {
    data += "<div data-attribute=\"" + requirement.attribute + "\" class=\"boxed\"><p>" + requirement.display + ": <select>"
    requirement.choices.forEach(function(choice)
    {
      data += "<option value=\"" + choice + "\"";
      if (node.hasOwnProperty(requirement.attribute) && node[requirement.attribute] == choice)
      {
        data += " selected";
      }
      data += ">" + choice + "</option>";
    });
    data += "</select></p></div>";
  }
  else
  {
    var i = 0;
    if (node.hasOwnProperty(requirement.attribute))
    {
      node[requirement.attribute].forEach(function(selectedNode)
      {
        data += createSelect(requirement, selectedNode);
        i+=1;
      });
    }
    var noneNode = {type:"None"};
    data += createSelect(requirement, noneNode);
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
      data += "<div class=\"boxed\">";
      var j = 0;
      selectedArray.forEach(function(selectedNode)
      {
        data += createSelect(requirement.requirement, selectedNode);
        j+=1;
      });
      var noneNode = {type:"None"};
      data += createSelect(requirement.requirement, noneNode);
      data += "</div>";
      i+=1;
    });
  }
  data += "<div class=\"boxed\">"
  var noneNode = {type:"None"};
  data += createSelect(requirement.requirement, noneNode);
  data += "</div>";
  return data;
}

function createSelect(requirement, selectedNode)
{
  var data = "<div data-attribute=\"" + requirement.attribute + "\" class=\"boxed\"><p>" + requirement.display + ": <select data-builderType=\"" + requirement.type + "\" onchange=\"updateSelect(this);\"><option value=\"None\">None</option>";
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

function updateSelect(select)
{
  $(select).parent().parent().find("div").remove();
  $(select).parent().parent().append(createNode({type: $(select).val()}, $(select).attr("data-builderType")));
  updateTheme();
}

function updateTheme()
{
  displayTheme($("#root"), getTheme($('#root')));
}

function getTheme(root)
{
  return getNode(root.find("div"));
}

function getNode(div)
{
  var node = {};
  var builder = builders[div.attr("data-interface")][div.attr("data-builder")];
  node.type = div.attr("data-builder");
  builder.requirements.forEach(function(requirement)
  {
    var attribute = div.find("[data-attribute='" + requirement.attribute + "']");
    if (requirement.type == "int")
    {
      node[requirement.attribute] = Number(attribute.find("p").find("input").val());
    }
    else if (requirement.type == "map")
    {
      var current = attribute.children().next();
      node[requirement.attribute] = {};
      while (current.length > 0 && current.first().is("p"))
      {
        var key = current.first().find("input").val();
        current = current.next();
        if (key != undefined && key.length > 0)
        {
          var submap = [];
          while (current.first().is("div"))
          {
            var builderSet = [];
            current.first().find("[data-attribute='undefined']").each(function()
            {
              if ($(this).find("p").find("select").val() != "None")
              {
                builderSet.push(getNode($(this).find("div")));
              }
            });
            if (builderSet.length > 0)
            {
              submap.push(builderSet);
            }
            current = current.next();
          }
          node[requirement.attribute][key] = submap;
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
      node[requirement.attribute] = attribute.find("p").find("select").val();
    }
    else
    {
      node[requirement.attribute] = [];
      attribute.each(function()
      {
        if ($(this).find("p").find("select").val() != "None")
        {
          node[requirement.attribute].push(getNode($(this).find("div")));
        }
      });
    }
  });

  return node;
}
