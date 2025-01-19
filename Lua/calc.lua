function add(a, b)
    return a + b
end

function subtract(a, b)
    return a - b
end

function multiply(a, b)
    return a * b
end

function divide(a, b)
    if b == 0 then
        return "Error: Division by zero is not allowed."
    else
        return a / b
    end
end

print("Welcome to the Lua Calculator!")
print("Choose an operation:")
print("1. Addition")
print("2. Subtraction")
print("3. Multiplication")
print("4. Division")
io.write("Enter your choice (1-4): ")
local choice = tonumber(io.read())

if choice >= 1 and choice <= 4 then
    io.write("Enter the first number: ")
    local num1 = tonumber(io.read())

    io.write("Enter the second number: ")
    local num2 = tonumber(io.read())

    if choice == 1 then
        print("Result: " .. add(num1, num2))
    elseif choice == 2 then
        print("Result: " .. subtract(num1, num2))
    elseif choice == 3 then
        print("Result: " .. multiply(num1, num2))
    elseif choice == 4 then
        print("Result: " .. divide(num1, num2))
    end
else
    print("Invalid choice! Please restart the program and try again.")
end
