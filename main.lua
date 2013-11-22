function foo()
   local ids = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
   result = {}
   for e in ipairs(ids) do
	  table.insert(result, has_entity(e))
   end
   return result
end

function main()
   print("Called the `main` main function.")
   print("Factorial:", factorial(10))
   print("Entity existence map:", table.unpack(foo()))
end

print("Loaded main.lua!")
