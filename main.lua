function foo()
    local ids = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    result = {}
    for e in ipairs(ids) do
        -- TODO: call has_entity from C code here:
        table.insert(result, e % 2 == 0)
    end
    return result
end

function main()
    print("Called the `main` main function")
    print(table.unpack(foo()))
end

print("Loaded main.lua!")
