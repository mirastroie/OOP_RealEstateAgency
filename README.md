# RealEstateAgency
My third project for the Object-oriented Programming course.

General Tasks
- templates, STL, static variables and functions, constants and const functions 
- RTTI
- exception handling
- object hierarchy concept
- constructors, destructors, assignment operator, friend function
- abstract class
- design patterns - singleton
- smart pointers

Create an application for a real-estate agency that manages clients and properties - apartments (`Apartament`) and houses (`Casa`). For each property, we know the name of the renter, the area, and the discount (0 - 10%).
For each apartment, we know the floor, and for each house, we know the area of the garden (in meters), how many floors it has, and the area for each
floor.
The formula of the rent for apartments is: 
`price of one meter * area`.
You have to take into consideration the discount where it is the case.
For the houses, you have to add, no matter the discount, the
price of the garden: 
`price for one meter of the garden * area`.
\
The data structure you have to use is
`set <pair<property, type>>` where the type can be `apartment` or `house`.
