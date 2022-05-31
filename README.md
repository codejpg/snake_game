<!-- ---
title: Creative Coding II
author: Angela Brennecke / India Aparicio
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 22
---   -->


## Theoretical Exercise(s) (2 pts)

- Review the container data structures, in particular, std::vector (or std::list) in order to implement the snake game
- Helpful functions are
  - push\_back(...)
  - insert(...)
  - front()
  - back()

Within C++ a vector is a sequence container, which represents arrays that can change in size. Vectors possess the ability to resize themselves automatically as soon as a new element is inserted or deleted - their storage handled automatically by the container. In the case of the snake game it is used in order to add length to the snakes body once the food is eaten (dynamically adding elements to the vector). 

The push_back method is used for adding elements to the vector, which allows for the snake tail to extend as values are added and additional squares drawn. 

The insert() function extends the vector by inserting elements at a *specified* position. The function accepts two parameters - the position and value of the new element. 

Finally the front() function allows access to the first element in the vector and returns a reference. Analogously, the back() function returns a reference of the last value in the vector.

## Practical Exercises (6 + 2 pts)

Functionality added:
- Snake growth
- Start screen, pause screen, game over
- Buttons to start and restart game
- Added font + stylized visuals
- Added a custom head for the snake
- Food changes color after being eaten
- Snake loops over game edges (may not be used in the end)
