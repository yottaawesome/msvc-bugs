# Module Class Member Function Breakpoints

## Introduction

In-class member function definitions do not have their breakpoints hit as expected.

As of 20/06/2023, this issue has been [reported to Microsoft](https://developercommunity.visualstudio.com/t/Debug-breakpoints-are-not-being-hit-in-m/10396206) and I'm waiting on a response.

Microsoft added this to their "Under consideration" queue, which is really their way of saying "we won't fix it anytime soon, if ever". Always set your bar low when you're dealing with MSFT or the MSVC team -- they're pretty inept, to put it mildly.

As of 02/11/2023, after more critical comments came in from different people, Microsoft has closed my ticket as a duplicate of [another ticket](https://developercommunity.visualstudio.com/t/Breakpoints-not-working-for-code-inside-/10449487) that was opened over two months after I opened mine. Evidently, after dumping my ticket into the ever-expanding "Under Consideration" pile, Microsoft promptly forgot about it. After I commented on that ticket, they finally marked the ticked as "Fixed -- pending release".

The entire episode was frankly bizarre and a prime demonstration that Microsoft often lacks initiative in fixing bugs; it was inevitable as more customers adopted C++20 modules, more of them would run into this broken debugging behaviour, but instead of doing the competent and proactive thing and resolving the issue before more customers noticed it, Microsoft kept its finger in its butt until more customers slammed them.

The whole episode would be funny if I hadn't been the one dealing with this broken debugging behaviour for the last six months.
