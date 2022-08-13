# Digital Counter
Digital counters are the devices that perform counting operations i.e., incrementing or decrementing the values of an operator, with respect to its previous state value. The counter cycles through the same sequence of numbers continuously so long as there is an incoming clock pulse. There exists several types of counters such as, synchronous counter, asynchronous counter, decade counter, binary counter, ring counter, johnson counter, up/down counter etc.

## Design
The digital counter circuit has been designed in Proteus. The circuit schematic is shown in Figure 1. In order to produce a stable output, the microcontroller is triggered with a stable clock input using a crystal oscillator and two capacitors. This provides the basic timing and control for a microcontroller and its peripherals. Both the oscillator and microcontroller operate at 20 MHz.<br>A 4-digit common cathode type seven-segment display is used to display the decimal count. As seen in the schematic, PORT B and PORT D of the microcontroller are used to configure the display. In order to give user the freedom to control the counter, two push-button switches are connected to PORT C for incrementing and decrementing the count. Another switch is connected to MCLR pin of the microcontroller to reset the counter.
<p align="center">
  <img src="https://github.com/rimshasaeed/digital-counter/blob/main/images/schematic.png", alt="circuit diagram" width="60%">
  <br>
  <i>Figure 1: Digital Counter Circuit Schematic</i>
</p>

## Simulation Results
#### 1. Up Counter
<p align="center">
  <img src="https://github.com/rimshasaeed/digital-counter/blob/main/images/up%20counter.png", alt="up counter" width="60%">
  <br>
  <i>Figure 2: When increment switch is pressed (up counter)</i>
</p>

#### 2. Down Counter
<p align="center">
  <img src="https://github.com/rimshasaeed/digital-counter/blob/main/images/down%20counter.png", alt="down counter" width="60%">
  <br>
  <i>Figure 3: When decrement switch is pressed (down counter)</i>
</p>

#### 3. Reset
<p align="center">
  <img src="https://github.com/rimshasaeed/digital-counter/blob/main/images/reset.png", alt="down counter" width="60%">
  <br>
  <i>Figure 4: When reset switch is pressed</i>
</p>
