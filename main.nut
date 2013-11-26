// TODO: should come from C
function has_entity(e) {
    return e > 0 && e < 10;
}

// TODO: should come from C
function factorial(n) {
    if(n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

function foo() {
    local ids = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
    local result = [];
    foreach(i, e in ids) {
         result.push(has_entity(e));
    }
    return result;
}

function main() {
    print("Called the `main` function.\n");
    print("Factorial: " + factorial(10) + "\n");
    print("Entity existence map: ");
    local map = foo();
    foreach(i, val in map) {
        print(val);
        if(i < map.len() - 1) {
            print(", ");
        } else {
            print("\n");
        }
    }
}
