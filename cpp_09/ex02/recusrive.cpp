/*

The Base Case (The Exit Strategy): 
A conditional statement that checks if the problem has been broken down to its absolute smallest unit.
 If true, it returns a hardcoded or simple value without calling the function again. Without this, 
 your program will loop infinitely until it crashes with a Stack Overflow.

The Recursive Step (The Progression): The section where the function calls itself, 
but crucially, passes a modified, smaller version of the original input. 
This ensures the function is constantly marching toward the Base Case.

Pseudo:

# 1. BASE CASE
if inputData is small enough or meets the stopping condition:
    return a simple, known result

# 2. LOGIC & PREPARATION
# (Do some work here if needed, like pairing elements or splitting data)
processedData = doSomethingWith(inputData)

# 3. RECURSIVE STEP
# Call the function again with smaller/modified data
result = recursiveFunction(processedData)

# 4. UNWINDING / COMBINING
# (Optional: Modify or combine the result as it travels back up the stack)
finalResult = combine(result, inputData)
return finalResult


*/