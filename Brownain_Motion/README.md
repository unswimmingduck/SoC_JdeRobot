# Brownian Motion

## Table of Contents

- [Background](#background)
- [Install](#install)
- [Usage](#usage)
- [Result show](#badge)

## Background

Brownian motion is the random movement of particles in a fluid due to their collisions with other atoms or molecules. Brownian motion is also known as _pedesis_, which comes from the Greek word for "leaping." Even though a particle may be large compared to the size of atoms and molecules in the surrounding medium, it can be moved by the impact with many tiny, fast-moving masses. Brownian motion may be considered a macroscopic (visible) picture of a particle influenced by many microscopic random effects.(If you want to learn more knowledgement about Brownain motion please click [here](https://www.thoughtco.com/brownian-motion-definition-and-explanation-4134272).)

## Install
This project use **Python**, **Pygame** and **Numpy** to simulate the Brownian Motion. So please make sure that you have downloaded the language and packages on your computer. What's more, if you want to visualize the track of the particle you have to install the **Matplotlib**.

### Pygame
The simplest way to install Pygame is via pip(If you want to know more about the Pygam API adn functions, you can click [here]()):

```sh
pip install pygame
```
### Numpy
The simplest way to install Numpy is via pip:

```sh
pip install numpy
```
### Matplotlib
The simplest way to install Numpy is via pip:

```sh
pip install matplotlib
```
### via git
Then you show clone clone the repository:
```sh
git clone https://github.com/unswimmingduck/Brownian_Motion
```


## Usage
You can run the simulation by the following command on your terminal:
```sh
cd Brownian_Motion
python main.py
```

You also can set the size of the screen and the size of the particle when you run the simulation:
```sh
python main.py --screen-width=600 --screen-length=800 --radius=6
```
(The default of the width is 400 and the default of the lenght is 400 too and the default size and the default of the particle size is 5. )

If you want to visualize the track of the particle, you can run the following command:
```sh
python main.py --screen-width=600 --screen-length=800 --radius=6 --output-track=True
```
## Result
Through the following gif we can see the simulation of Brownian Motion directly:
<div align=center>
<img src="https://github.com/unswimmingduck/SoC_JdeRobot/blob/master/Brownain_Motion/result/result.gif" width="350" height="350">
</div>
What's more, we can use relevant command to plot the track of particle by Matlotlib. The following picture is the reult which is ploted by the Matplotlib:
<div align=center>
<img src="https://github.com/unswimmingduck/SoC_JdeRobot/blob/master/Brownain_Motion/result/result.png" width="350" height="350">
</div>
