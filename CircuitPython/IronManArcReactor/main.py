# Name:  Joshua Sew-Hee
# Date: April 26, 2019
# Program: Ironman Arc Reactor


import time
from adafruit_circuitplayground.express import cpx

def switch():
    print("Slide switch:", cpx.switch)
    time.sleep(0.1)

def blink_neo_pixels(r, g, b, delay_on, delay_off):
    cpx.pixels.fill((r, g, b))
    time.sleep(delay_on)
    # turn neo pixels off
    cpx.pixels.fill((0, 0, 0))
    time.sleep(delay_off)
    
def n_neo_pixels(n, r, g, b):
    cpx.pixels[n] = (r, g, b)

def ring_neo_pixels():
    for i in range(10):
        n_neo_pixels(i, 15*i, 10*i, 25*i)
        time.sleep(.5);
        n_neo_pixels(i, 0, 0, 0)

def neo_pixels_flower():
    for i in range(235):
        cpx.pixels.fill((0, 20+i, 20+i))

# This function
def neo_pixels_glow():
    for i in range(10):
        # Cyan glow
        cpx.pixels.fill((0, 25*i, 25*i))
        
        # Purple glow
        #cpx.pixels.fill((25*i, 0, 25*i))
        

brightness = 1.0

# adjust brightness of the neo pixels
cpx.pixels.brightness = brightness

while True:
    if cpx.button_a:
        cpx.play_tone(440, 1)
    elif cpx.button_b:
        cpx.play_file("outta_here.wav")
    elif cpx.switch:
        #neo_pixels_flower()
        # Blink Ironman Arc Reactor glow
        neo_pixels_glow()
    else:
        # Turn the light off
        #cpx.pixels.fill((0, 0, 0))
        
        # Full lights on
        #cpx.pixels.fill((0, 255, 255))
        
        # Blink Ironman Arc Reactor like a flower motion
        neo_pixels_flower()
        
        # blink in red
        #blink_neo_pixels(125, 0, 0, 0.8, 0.5)
        
        
        