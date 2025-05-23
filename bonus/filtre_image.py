#==============================================================================#
# Nom du Programme:
#------------------------------------------------------------------------------#
# Auteur:Côme
# date:¯\_(ツ)_/¯
#======================================================================#
#----------------------------------------------------------#
# Importation des modules externes #
#----------------------------------------------------------#
import os
from PIL import Image
#--------------------------------------------------#
# Définition des fonctions #
#--------------------------------------------------#
def FiltreRouge(img):
    hauteur = len(img)
    largeur = len(img[0])
    new = []
    for y in range(hauteur):
        new.append([])
        for x in range(largeur):
            new[y].append(0)
    for y in range(hauteur):
        for x in range(largeur):
            new[y][x]=[img[y][x][0],0,0]
    return new
"""------------docstring---------------------------"""

def FiltreVert(img):
    hauteur = len(img)
    largeur = len(img[0])
    new = []
    for y in range(hauteur):
        new.append([])
        for x in range(largeur):
            new[y].append(0)
    for y in range(hauteur):
        for x in range(largeur):
            new[y][x]=[0,img[y][x][1],0]
    return new
"""------------docstring---------------------------"""

def FiltreBleu(img):
    hauteur = len(img)
    largeur = len(img[0])
    new = []
    for y in range(hauteur):
        new.append([])
        for x in range(largeur):
            new[y].append(0)
    for y in range(hauteur):
        for x in range(largeur):
            new[y][x]=[0,0,img[y][x][2]]
    return new
"""------------docstring---------------------------"""

def FiltreNoir(img):
    hauteur = len(img)
    largeur = len(img[0])
    new = []
    for y in range(hauteur):
        new.append([])
        for x in range(largeur):
            new[y].append(0)
    for y in range(hauteur):
        for x in range(largeur):
            color = moy(img[y][x][0], img[y][x][1], img[y][x][2])
            new[y][x]=[color,color,color]
    return new
"""------------docstring---------------------------"""

def FiltreBorder(img):
    hauteur = len(img)
    largeur = len(img[0])
    new = []
    for y in range(hauteur):
        new.append([])
        for x in range(largeur):
            new[y].append(0)
    for y in range(hauteur):
        for x in range(largeur):
            if (x == largeur - 1 or x == 0 or y == hauteur - 1 or y == 0):
                new[y][x]=[255,0,0]
            else:
                new[y][x]=[img[y][x][0],img[y][x][1],img[y][x][2]]
    return new
"""------------docstring---------------------------"""

def transformer_image_en_liste(img):
    X,Y = img.size
    liste=()
    liste_image=[[0 for y in range(Y)] for x in range(X)]
    for y in range(Y):
        for x in range(X):
            pixel = img.getpixel((x,y)) # récupération du pixel
            liste =(pixel[0],pixel[1],pixel[2])

            liste_image[x][y] = liste
    return liste_image
"""------------docstring---------------------------"""

def transformer_liste_en_image(liste):
    X = len(liste)
    Y = len(liste[0])
    image = Image.new('RGB',(X,Y))
    for y in range(Y):
        for x in range(X):
            image.putpixel((x,y),tuple(liste[x][y]))
    return image
"""------------docstring---------------------------"""

def moy(r, g, b):
    return (int)((r + g + b) / 3) - 50
"""------------docstring---------------------------"""
#-------------------------------------------------#
# Programme principal #
#-------------------------------------------------#
path = "buttons"
paths = [os.path.abspath(os.path.join(path, ent)) for ent in os.listdir(path)]

for i in paths:
    image = Image.open(i)
    img = transformer_image_en_liste(image)
    img = FiltreBorder(img)
    final = transformer_liste_en_image(img)
    final.save(i.replace("buttons","border"))
