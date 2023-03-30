import sys
import pygame
from pygame.sprite import Sprite
import numpy as np
import math

class Particle(Sprite):
    def __init__(self, screen:pygame.Surface, radius, position_x, position_y):
        super().__init__()

        self.onestep = np.random.uniform(0,5)
        self.radius = radius
        self.image = pygame.Surface((40, 40))
        self.rect = self.image.get_rect()
        self.track_x = [0]
        self.track_y = [0]

        self.image.fill((255,255,255))
        pygame.draw.circle(self.image, (0,0,255), (20, 20), self.radius)
        self.rect.centerx = position_x
        self.rect.centery = position_y



    def move(self, screen:pygame.Surface):
        self.onestep = np.random.uniform(0,5)
        limatation_x, limatation_y =screen.get_size()

        theta = np.random.uniform(0, (2*math.pi))
        next_x = self.rect.centerx + self.onestep*math.cos(theta)
        next_y = self.rect.centery + self.onestep*math.sin(theta)

        if next_x - self.radius < 0:
            next_x =  -next_x/2
        elif next_y - self.radius < 0:
            next_y = -next_y/2
        elif next_x - self.radius > limatation_x:
            next_x = limatation_x - (next_x - limatation_x)
        elif next_y - self.radius > limatation_y:
            next_y = 2*limatation_y - next_y

        self.rect.centerx = next_x
        self.rect.centery = next_y
        self.track_x.append(self.rect.centerx - limatation_x/2)
        self.track_y.append(self.rect.centery - limatation_y/2)
