import pygame
from random import randint
from pygame import mixer
import math
import timeit

# Initialise the pygame
pygame.init()

# score
scoreValue = 0
scoreComplexity = 0
font = pygame.font.Font('freesansbold.ttf', 32)


def showScore(x, y):
    score = font.render("Score : " + str(scoreValue), True, (255, 255, 255))
    screen.blit(score, (x, y))


def showTime(x, y, st):
    score = font.render(
        "Time : " + st[0] + '.' + st[1][0] + 's', True, (255, 255, 255))
    screen.blit(score, (x, y))


# Game Over
gameOverVar = False
gameOver = pygame.font.Font('freesansbold.ttf', 64)


def showGameOver(x, y):
    go = gameOver.render("Game Over!", True, (255, 255, 255))
    screen.blit(go, (x, y))


# Background music
mixer.music.load('sounds/background.wav')
mixer.music.play(-1)

# create the screen
scr_width = 800
scr_height = 800
screen = pygame.display.set_mode((scr_width, scr_height))

# Title and icon
pygame.display.set_caption("SpaceInvaders")
icon = pygame.image.load('space.png')
pygame.display.set_icon(icon)

# Background
backImg = pygame.image.load('back/back.jpg')

# Enemy
enemyImg = []
enemyWidth = []
enemyHeight = []
enemyX = []
enemyY = []
enemyChangeX = []
enemyChangeY = []

numEnemies = 1


def addEnemy(image):
    global numEnemies
    enemyImg.append(pygame.image.load(image))
    i = len(enemyImg) - 1
    enemyWidth.append(int(enemyImg[i].get_rect().size[1]))
    enemyHeight.append(int(enemyImg[i].get_rect().size[0]))
    enemyX.append(randint(0, scr_width - enemyWidth[i]))
    enemyY.append(randint(int(0.001*scr_height), int(0.2*scr_height)))
    enemyChangeX.append(0.2)
    enemyChangeY.append(enemyHeight[i])


for i in range(numEnemies):
    addEnemy('enemy/monster.png')

# Player
playerImg = pygame.image.load('player/spaceship.png')
playerWidth = int(playerImg.get_rect().size[1])
playerX = scr_width/2 - playerWidth/2
playerY = int(0.8*scr_height)
playerChangeX = 0
playerSpeed = 0.4
playerSpeedDef = 0.4

# Bullet
bulletImg = pygame.image.load('player/bullet.png')
bulletWidth = int(bulletImg.get_rect().size[1])
bulletHeight = int(bulletImg.get_rect().size[0])
bulletX = 0
bulletY = playerY
bulletChangeX = 0
bulletChangeY = 2
bulletChangeYDef = 2
bulletState = 'ready'


def player(x, y):
    screen.blit(playerImg, (x, y))


def enemy(i, x, y):
    screen.blit(enemyImg[i], (x, y))


def fireBullet(x, y):
    global bulletState
    bulletState = "fire"
    screen.blit(bulletImg, (x + bulletWidth/2, y + bulletHeight/2))


def isCollision(i, enemyX, enemyY, bulletX, bulletY):
    distance = math.sqrt((math.pow(enemyX - bulletX, 2)) +
                         (math.pow(enemyY - bulletY, 2)))
    if (distance < enemyWidth[i]/2):
        return True
    else:
        return False


# Game Loop
running = True
startTime = timeit.default_timer()
while running:
    screen.fill((25, 25, 25))
    screen.blit(backImg, (0, 0))
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                playerChangeX = -playerSpeed
            if event.key == pygame.K_RIGHT:
                playerChangeX = playerSpeed
            if event.key == pygame.K_SPACE and bulletState == 'ready':
                bulletSound = mixer.Sound('sounds/laser.wav')
                bulletSound.play()
                bulletX = playerX
                fireBullet(bulletX, bulletY)
            if event.key == pygame.K_BACKSPACE and gameOverVar == True:
                gameOverVar = False
                scoreValue = 0
                # print("restarted")
                for j in range(numEnemies):
                    enemyImg.pop()
                    enemyWidth.pop()
                    enemyHeight.pop()
                    enemyChangeX.pop()
                    enemyChangeY.pop()
                    enemyX.pop()
                    enemyY.pop()
                addEnemy('enemy/monster.png')
                numEnemies = 1
                bulletState = 'ready'
                playerSpeed = playerSpeedDef
                bulletChangeY = bulletChangeYDef
                startTime = timeit.default_timer()
                mixer.music.play(-1)

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                playerChangeX = 0

    # Game Complexity
    if (int(scoreValue/10) != scoreComplexity):
        scoreComplexity = int(scoreValue/10)
        for i in range(numEnemies):
            enemyChangeX[i] *= 1.35
        playerSpeed *= 1.5
        bulletChangeY *= 1.5

    if int(scoreValue/(numEnemies + 1)) >= numEnemies:
        if numEnemies % 2 == 0:
            addEnemy('enemy/alien.png')
        else:
            addEnemy('enemy/monster.png')
        print(numEnemies)
        numEnemies += 1
    # setting boundaries
    playerX += playerChangeX
    if (playerX <= 0):
        playerX = 0
    elif (playerX >= scr_width - playerWidth):
        playerX = scr_width - playerWidth

    # Game Over Check
    if gameOverVar:
        showGameOver(scr_width/2 - 200, scr_height/2)
        # print("Game over")
        continue

    # Enemy Movement
    for i in range(numEnemies):
        collisionPlayer = isCollision(
            i, enemyX[i], enemyY[i], playerX, playerY) or enemyY[i] >= playerY
        if collisionPlayer:
            collSound = mixer.Sound('sounds/explosion.wav')
            for j in range(numEnemies):
                enemyY[j] = 1000
            showGameOver(scr_width/2 - 170, scr_height/2)
            mixer.music.stop()
            gameOverVar = True
            break

        enemyX[i] += enemyChangeX[i]
        if (enemyX[i] <= 0):
            enemyX[i] = 0
            enemyChangeX[i] = -enemyChangeX[i]
            enemyY[i] += enemyChangeY[i]
        elif (enemyX[i] >= scr_width - enemyWidth[i]):
            enemyX[i] = scr_width - enemyWidth[i]
            enemyChangeX[i] = -enemyChangeX[i]
            enemyY[i] += enemyChangeY[i]

        enemy(i, enemyX[i], enemyY[i])

        # collision
        collision = isCollision(i, enemyX[i], enemyY[i], bulletX, bulletY)
        if collision:
            collSound = mixer.Sound('sounds/explosion.wav')
            collSound.play()
            bulletY = playerY
            bulletState = 'ready'
            scoreValue += 1
            # print(scoreValue)
            enemyX[i] = randint(0, scr_width - enemyWidth[i])
            enemyY[i] = randint(int(0.1*scr_height), int(0.3*scr_height))

    # bullet movement
    if bulletY <= 0:
        bulletY = playerY
        bulletState = 'ready'

    if bulletState == 'fire':
        fireBullet(bulletX, bulletY)
        bulletY -= bulletChangeY

    player(playerX, playerY)
    showScore(5, 5)
    showTime(scr_width/2, 5, str(timeit.default_timer() - startTime).split('.'))
    pygame.display.update()
    pass
