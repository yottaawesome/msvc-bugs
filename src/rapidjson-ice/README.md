# RapidJSON and std::format ICE

## Introduction

There's some strange interaction between module header units, std::format, and rapidJSON that causes an ICE.

This issue was [reported](https://developercommunity.visualstudio.com/t/Interaction-between-module-header-unit/10290197) today (24/02/2023) and shortly later reported as fixed by Microsoft.
