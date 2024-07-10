# Daisy_QSPI_Flasher

Welcome to the Daisy QSPI Flasher project!  
*Bienvenue dans le projet Daisy QSPI Flasher !*

Daisy QSPI Flasher is a utility that allows you to load files (samples, images, etc.) into the QSPI Flash memory of the ElectroSmith Daisy Seed board (https://electro-smith.com/).  
*Daisy QSPI Flasher est un utilitaire qui permet de charger des fichiers (samples, images, ...) dans la mémoire Flash QSPI de la carte Daisy Seed de ElectroSmith (https://electro-smith.com/).*

The project consists of two parts:  
*Le projet se compose de deux parties :*
- A Windows Server: File selection and transfer to the Daisy Seed.  
  *Un Serveur sous Windows : Choix des fichiers et transfert vers la Daisy Seed.*
- A Client on the Daisy Seed board: Receives the files and stores them in the QSPI Flash memory.  
  *Un Client sur la carte Daisy Seed : Reçoit les fichiers et les enregistre dans la mémoire Flash QSPI.*

## Using the utility / *Utilisation de l'utilitaire*
1. Connect Daisy Seed to your PC via the USB cable.  
   *Connecter Daisy Seed à votre PC par le câble USB.*
2. Load and run the client on the Daisy Seed board.  
   *Charger et exécuter le client dans la carte Daisy Seed.*
3. On the PC, launch the FlasherServer.exe program.  
   *Sur le PC lancer le programme FlasherServer.exe.*
4. In FlasherServer.exe: Add files; Select the COM port number connected to the Seed; Start data transmission (Flash button).  
   *Dans FlasherServer.exe : Ajouter les fichiers ; Sélectionner le numéro port COM relié à la Seed ; Lancer la transmission des données (Bouton Flash).*
5. In your application, the cQSPI class allows you to retrieve the address of files in QSPI flash memory.  
   *Dans votre application, la classe cQSPI permet de retrouver l'adresse des fichiers en mémoire flash QSPI.*

```cpp
#include "Flasher.h"		       			
//…
Dad::cQSPI DSY_QSPI_BSS __QSPI;   // Global declaration of the QSPI memory management class
//…
pSound = __QSPI.GetFilePtr("Sound.wav")  // Read file address into memory
```
## Sources

Clone the project / *Clonez le projet* :
```sh
git clone --recurse-submodules https://github.com/DADDesign-Projects/Daisy_QSPI_Flasher your_directory
```
### Client

The code can be modified and compiled in VS Code within the Daisy Seed development environment (see https://github.com/electro-smith).  
Le code est modifiable et compilable sous VS Code dans l’environnement de développement du Daisy Seed (voir https://github.com/electro-smith).  
#### Configuration
Adapt the Makefile to the location of the libraries:  
*Le fichier Makefile est à adapter en fonction de l’emplacement des librairies :*
```
LIBDAISY_DIR = ../../../Desktop/DaisyExamples/libDaisy/
DAISYSP_DIR = ../../../Desktop/DaisyExamples/DaisySP/
```
Adapt the .vscode/c_cpp_properties.json file as well:  
*Le fichier .vscode/c_cpp_properties.json est aussi à adapter :*
```
"includePath": [
  "${workspaceFolder}/**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/libDaisy//**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/DaisySP//**"
```
### Server

The code is written under Microsoft Visual Studio 2022.  
*Le code est écrit sous Microsoft Visual Studio 2022.*

**Don't hesitate to contact me if you have any questions or suggestions.**  
**N'hésitez pas à me contacter si vous avez des questions ou des suggestions.**
