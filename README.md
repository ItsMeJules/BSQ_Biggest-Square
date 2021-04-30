# BSQ_Biggest-Square
This is our BSQ algorithm made with my friend during our C Piscine @42Paris. <br />
It's actually working but fails in some cases which I'll be fixing when I'll have the courage to (I won't it's been 6 months now.)

# Speed
These tests were made on a computer with an `Intel® CoreTM i7-9750H 9th gen` with `GeForce GTX 1660 Ti Max-Q` as a GPU and `16GB DDR4` of ram.
- 0.076s (with display time) on a 1kx1k map with 10 density
- 7.911s (with display time) on a 10kx10k map with 100 density
- 38.607s (with display time) on a 20kx20k map with 200 density

# Tips
Use a `char *` tab to store your map and run through it, it will significantly increase the speed of your programm as it's "side by side in memory".
When you expand your square check only the outter right and bottom borders of it (if you start drawing from the top left corner)
Check if the length/width of the square will fit at the next position you are looking for
...
