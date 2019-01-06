# reflection

## how i set the P, I and D values

i set them manually but one, by one. so i started with 'P-only' **{1, 0, 0}**.
that obviously (as expected) could not work, since the miss steering will add up pretty much and result in an uncontrolable 
slingery movement. but i needed to get a feeling for the impact of the value. as a result i changed it to **{0.1, 0, 0}**
and found the movements way smoother.

from there i had to supress the adding wave like movement, so i added the 'D-component'. due to the experience with P, 
i choose 0.1 for starters so i had **{0.1, 0.1, 0}**. i noticed that the reaction to miss steerings came to late wich let me
increase the value step-by-step till i ended up with D at 0.9. so my current setup was **{0.1, 0.9, 0}**

from here the car was already able to make it around the track, but it still looked pretty rough and edgy. so to smooth it
a bit i finally added the I-component. here i started with 0.1 as well, but noticed pretty fast that especially in the 
beginning it lead to heavy over steering. so i decreased it a lot till i finally got my settings of **{0.1, 0.9, 0.002}**

since i still noteced some problems in the beginning i also added some kind of special handling for the start period of the 
car. so basically i 'virtually reduced' the cte that was given to the function calculating the steering angle, with a linear
factor of **_speed/23_**, which i disabled as soon as the car reached a velocity greater than 23.
