
# Excrise

<div align=center><img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white"> <img src="https://img.shields.io/badge/GIT-E44C30?style=for-the-badge&logo=git&logoColor=white"> <img src="
https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white"> 
</div>

## Table of Contents

- [Docker](#docker)
- [Excrise](#excrise)


# 1.  Docker
<img src="https://img.shields.io/badge/Docker----blue">

### 1.1 [The introduction of Docker](https://www.infoworld.com/article/3310941/why-you-should-use-docker-and-containers.html)

Docker containers provide a way to get a grip on software. You can use Docker to wrap up an application in such a way that its deployment and runtime issues—how to expose it on a network, how to manage its use of storage and memory and I/O, how to control access permissions—are handled outside of the application itself, and in a way that is consistent across all “containerized” apps. You can run your Docker container on any OS-compatible host (Linux or Windows) that has the Docker runtime installed.

Docker offers many other benefits besides this handy encapsulation, isolation, portability, and control. Docker containers are small (megabytes). They start instantly. They have their own built-in mechanisms for versioning and component reuse. They can be easily shared via the public  Docker Hub  or private repository.

**So the Docker can enusre the JdeRobot projects be run on most types of system.**

If you want to obtain more informations about how tot use Docker, you can visit their [official web](https://www.docker.com/) .



###  1.2 The installation of Docker
In [here](https://docs.docker.com/get-docker/), you can get to know how to install the Docker that fits your machine.

My computer's system is Win10. But, in order to make it more convenient to use the Docker, I deployed the Docker on my **VMware with Ubuntu 18**.

###  1.3 Pull the current distribution of Robotics Academy Docker Image
```sh
docker pull jderobot/robotics-academy:latest
```
You can get more information about how to pull the current distribution of Robotics Academy Docker Image on [JdeRobot official web](https://jderobot.github.io/RoboticsAcademy/user_guide/).

###  1.4 Using the Docker to perform the exercises

**Firstly**,  you should start the Docker. Depending on different types that you deploy the Docker on, there have different commands to start the Docker. If you use the Ubuntu to deploy the Docker, you can use the following command on the terminal to start the Docker service:
```sh
sudo service docker start
```
**Secondly**, you can start a new docker container of the image and keep it running in the background by the following command:
```sh
docker run --rm -it -p 8000:8000 -p 2303:2303 -p 1905:1905 -p 8765:8765 -p 6080:6080 -p 1108:1108 -p 7163:7163 jderobot/robotics-academy
```
**Then**, on the local machine navigate to 127.0.0.1:8000/ in the browser you can choose the desired exercise(In [here](https://jderobot.github.io/RoboticsAcademy/exercises/), you can get the summary of all excrises).
You can get more informations about how to using the Docker to perform the exercises on the [JdeRobot official web](https://jderobot.github.io/RoboticsAcademy/user_guide/).

# 2. Excrise

<img src="http://ForTheBadge.com/images/badges/made-with-python.svg">


##  Follow Line

In this excrise, you should write a code program to cotroll the F1 to follow the line. In the excrise you should use the camera to detect the line and use some knowledgements about CV(computer version) to process the images so that you can ensure that the F1 always follow the line. In [here](https://jderobot.github.io/RoboticsAcademy/exercises/AutonomousCars/follow_line/), you can get more informations about this excrise.

## Method
<img src = "https://img.shields.io/badge/opencv-2-orange">

In order to making sure that the F1 always follow the line, we should detect the line and check the how far the F1 deviates from the center of the line. Then, accroding to the deviation, we control the angular velocity of F1 to make sure the F1 follow the line.
<div align=center><img src="https://github.com/unswimmingduck/SoC_JdeRobot/blob/master/JdeRobot_excrise/Follow_Line/README/Follow_Line.png" width="350" height="350"></div>
### 1.1 The detection of the line
**Firstly**, we should convert image format. We will convert the BGR image to HSV image. This is because that **HSV** is very intuitive to express the hue, vividness and brightness of the color, convenient for color comparison. In the color space of HSV, it is easier to track objects of a certain color than BGR. It is often used to segment objects of a specified color.

**Secondly**, we use **cv2.inRang()** to detect the accroding color of the line. In this way we can get the mask of the line.

### 1.2 Further process of the image
We will use the **cv2.dilate()** and then use **cv2.erode()** to process the image. In this way, we can make the F1 to know more informations about farther road. As a result, the F1 can handle sharp turns better.

### 1.3 Caculate the center of the line mask
We can use the **cv2.moments()** to compute the center of the line in the image. Then let's subtract the center of the image from the center of the line. As a result, we can get a deviation. According to the deviation, we can use the **PID** to control the F1.

### 1.4 Use the PID to control the F1
In this situation, we can directly set the angular velocity of the F1. So we chose the **Positional PID** to controll the F1. The equation of the **Positional PID** is in the following:
<div align=center><img src="https://github.com/unswimmingduck/SoC_JdeRobot/blob/master/JdeRobot_excrise/Follow_Line/README/Positional_PID.png"></div>

**What's more, the Kp, Ki, Kd in the github folder is not correct. So if you want to know the right parameters please leave a message or send me an email(zhoum1440@gmail.com)**.  
<img src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white">

## Result   

<img src="https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white">

You can watch the result of my excrise in [YouTube](https://youtu.be/-oZB0JRg9Ho). 



