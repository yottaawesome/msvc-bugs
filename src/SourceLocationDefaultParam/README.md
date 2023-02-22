# Source Location Default Parameter ICE

## Introduction

This project covers a particular MSVC bug that has been observed since VS2019 and which continues persisting into VS2022. This bug manifests as an internal compiler error (ICE) and occurs when a souce file that does not include `<source_location>` throws a type that has `std::source_location` as a default parameter. As soon as the offending file includes `<source_location>`, the issue goes away. Curiously, this bug doesn't occur if the type is first constructed and then thrown in separate statements, nor does it occur when invoking functions or function members that have `std::source_location` as a default parameter.

As of 22/02/2023, this issue has been [reported](https://developercommunity.visualstudio.com/t/std::source_location-can-cause-ICEs-when/10287637) to Microsoft for further evaluation.