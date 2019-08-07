function FilterPlatforms(filters)
  filters = filters or {}

  
  function fp(file)
    result = {}

    table.foreachi(filters, function (filter)
      table.insertflat(result, string.contains(file, filter))
    end)

    if table.contains(result, true) then
      return false
    else 
      return true
    end
  end

  return fp
end

function GetHeaders(directory, filters)
  return table.join(
    table.filter(os.matchfiles(path.join(directory, "**.hpp")), FilterPlatforms(filters)),
    table.filter(os.matchfiles(path.join(directory, "**.inl")), FilterPlatforms(filters)),
    table.filter(os.matchfiles(path.join(directory, "**.h")), FilterPlatforms(filters))
  )
end

function GetSources(directory, filters)
  return table.join(
    table.filter(os.matchfiles(path.join(directory, "**.cpp")), FilterPlatforms(filters)),
    table.filter(os.matchfiles(path.join(directory, "**.c")), FilterPlatforms(filters)),
    table.filter(os.matchfiles(path.join(directory, "**.cc")), FilterPlatforms(filters))
  )
end

function GetAll(directory)
  return { 
    path.join(directory, "**.hpp"), 
    path.join(directory, "**.cpp"),
    path.join(directory, "**.h"), 
    path.join(directory, "**.c"),
    path.join(directory, "**.cc")
  }
end
