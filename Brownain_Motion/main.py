import sys
import pygame
import argparse
from Particle import Particle
from matplotlib import pyplot as plt

def main():
    parser = argparse.ArgumentParser(description='PyTorch MNIST Example')
    parser.add_argument('--screen-width', type=int, default=400,
                        help='input size for the width of screen (default: 400)')
    parser.add_argument('--screen-length', type=int, default=400,
                        help='input size for the length of screen (default: 400)')
    parser.add_argument('--radius', type=int, default=5,
                        help='input size of the particle (default: 5)')
    parser.add_argument('--output-track', type=bool, default=False,
                        help='decide whether output the track of particle(default: False)')        
    args = parser.parse_args()

    if(args.output_track == True):
        plt.figure()
        plt.title("The track of the particle")
        plt.xlim(-(args.screen_length/2), args.screen_length/2)
        plt.ylim(-(args.screen_width/2), args.screen_width/2)
        ax = plt.gca()
        ax.spines['right'].set_color('none')
        ax.spines['top'].set_color('none')
        ax.xaxis.set_ticks_position('bottom')
        ax.spines['bottom'].set_position(('data', 0))
        ax.yaxis.set_ticks_position('left')
        ax.spines['left'].set_position(('data',0))


    pygame.init()
    screen = pygame.display.set_mode((args.screen_length,args.screen_width))
    screen.fill((255,255,255))
    pygame.display.set_caption("Brown Movement")
    circle = Particle(screen, args.radius, args.screen_length/2, args.screen_width/2)
    
    clock = pygame.time.Clock()
    screen.blit(circle.image, circle.rect)
    
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                if (args.output_track==True):
                    plt.plot(circle.track_x, circle.track_y)
                    plt.show()
                    plt.close('all')
                pygame.quit()
                sys.exit()
                
            
        circle.move(screen)
        screen.blit(circle.image, circle.rect)
        
        pygame.display.update()   
        clock.tick(240)


if __name__ == "__main__":
    main()