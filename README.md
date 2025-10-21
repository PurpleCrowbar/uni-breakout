# Breakout

W Kavanagh & N Merchant. Summer 2024 

## controls

A/D to move the paddle right and left.
P to pause.

## Powerups

big/small paddle (blue)
fast/slow ball (fancy yellow)
fire ball (green)

# Tasklist

## Suggested fixes

* Fix the compiler issues in the code

## Suggested tasks

* Implement mouse input for pad
* Improved VFX (ball trail, paddle hit response, brick particle destruction)
* Better UI (progress bar rather than timer for countdown).
* GameLoop
* Better ball physics (Box2D)
* Leaderboards
* More ball types (e.g., multiball, sticky ball [where you shoot the ball from the paddle every time], tiny ball, big ball, brick-tracking ball)
* Sounds with increasing tone between bounces.
* Implement commentary with calls to an LLM such as LLama

# Time Details and Changelist
I spent about 4 hours on this task. Here is a list of changes I made:

1. Compiler error fixes
2. Shift GameManager getter definitions to header file
3. Clean up unused imports
4. Implement multicoloured bricks (each row has unique colour)
5. Update paddle to follow mouse pointer
6. Implement screen shake when taking damage
7. Add background music, sound effect for taking damage, and sound effect for breaking bricks (which increases in pitch for each brick broken)