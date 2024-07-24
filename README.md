Compiled in VS2022. Complied files are removed to ensure the attachment won't be blocked by your corporate firewall. The solution can be very easily built in VS (by clicking Build->Build Solution).


Task1:
* Please see Task1.sln. Some driver code was included in the main function for demonstration.
* Please see CppPythonWrapper for Step 3 and 4.

Task2:
* Please see Task2.sln. The code uses void* and pointer to member to sort vector of any custom type (by template). It aims to be as generic as poosible. 
However, it won't compile due to C++ won't allow conversion between void* and T::*memberPtr (also tried casting but didn't work). Can't figure out.
