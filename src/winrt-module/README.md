# C++/WinRT in Modules

## Introduction

MSVC appears to be behaving inconsistently when using C++/WinRT in C++ modules for some reason.

As of 29/06/2023, this issue has been [reported to Microsoft](https://developercommunity.visualstudio.com/t/Strange-compiler-behavior-when-using-C/10404101?sort=newest).

As of 03/07/2023, Microsoft has bizarrely closed the issue as "not a bug" citing that a template needs to be exported. Microsoft's response makes no sense and doesn't explain why compilation succeeds when the constructor is defined out-of-class. I suspect they only read half of what I wrote and then skipped the rest, which is the second such instance they've done this. Anyway, I reached out for further clarification and they ignored me, which is expected given their ineptitude.
