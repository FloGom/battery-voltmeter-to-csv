# -*- coding: utf-8 -*-
"""
Created on Thu Feb 16 11:40:09 2017

@author: florentin
"""

import serial
from os import getcwd

## paramètres du port série
#port = input("Quel numéro de port COM voulez-vous écouter?\n")
#vitesse = int(input("Quelle vitesse en baud?\n"))
#caracFin = input("Quel(s) caractère(s) de fin de communication?\n")
#
#print("Dossier de travail : \n", getcwd(), '\n')
#cheminFichier = input("Chemin du fichier csv\n")

port = str(6)
vitesse = 9600
caracFin = "stop"
cheminFichier = "H4WDB_statsPiles_170216_AAA_test.csv"

# initialisation du port série
ser = serial.Serial('COM' + port, vitesse)
if(ser.isOpen()):
    print("Port série COM{} ouvert.".format(port))

ligne = ""
with open(cheminFichier, 'w') as outfile:
    while(not(ligne == caracFin)):
        # on vérifie s'il y a des caractères en attente dans le buffer
        if(ser.inWaiting()):
            ligne = ser.readline()[:-2].decode("utf-8") #on enlève \r\n
            print(ligne)#, ligne==caracFin)
            outfile.write(ligne.replace('.',',') + '\n')

ser.close()

print("Finis")
