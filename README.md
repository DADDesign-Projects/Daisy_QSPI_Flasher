# Daisy_QSPI_Flasher
Bienvenue dans le projet Daisy QSPI Flasher !  
Daisy QSPI Flasher est un utilitaire qui permet de charger des fichiers (samples, images, ...) dans la mémoire Flash QSPI de la carte Daisy Seed de ElectroSmith ( https://electro-smith.com/).

Le projet se compose de deux parties :
- Un Serveur sous Windows : Choix des fichiers et transfert vers la Daisy Seed.
- un Client Client sur la carte Daisy Seed : Reçoit les fichiers et les enregistre dans la mémoire Flash QSPI.
## Utilisation de l'utilitaire
1) Connecter Daisy Seed à votre PC par le cable USB
2) Charger et executer client dans le carte Daisy Seed.
3) Sur le PC télécharger et lancer le programme FlasherServer.exe
4) Dans FlasherServer.exe : Ajouter les fichiers; Selectionner le numéro port COM relié a la Seed; Lancer la transmission des données (Bouton Flash).
5) Dans votre application La classe cQSPI (fichier FLASHER.h) permet de retrouver l'adresse des fichiers en mémoire flash QSPI.     
```
Dad::cQSPI DSY_QSPI_BSS __QSPI;
...
pSound = __QSPI.GetFilePtr("Sound.wav")
```

## Sources
Clonez le projet / Clone the project:
```
  git clone --recurse-submodules https://github.com/DADDesign-Projects/Daisy_QSPI_Flasher VotreDossier
```
### Client
Le code est modifiable et compilable sous VS Code dans l’environnement de développement du Daisy Seed (voir https://github.com/electro-smith).  
The code can be modified and compiled in VS Code within the Daisy Seed development environment (see https://github.com/electro-smith).

#### Configuration 
1. Le fichier Makefile est à adapter en fonction de l’emplacement des librairies / Adapt the Makefile to the location of the libraries : 
```
  LIBDAISY_DIR = ../../../Desktop/DaisyExamples/libDaisy/
  DAISYSP_DIR = ../../../Desktop/DaisyExamples/DaisySP/
```
3. Le fichier .vscode/c_cpp_properties.json est aussi à adapter / Adapt the .vscode/c_cpp_properties.json file as well :
```
"includePath": [
  "${workspaceFolder}/**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/libDaisy//**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/DaisySP//**"
```
### Serveur
Le code est ecrit sous Microsoft Visual Studio 2022.

**N'hésitez pas à me contacter si vous avez des questions ou des suggestions.**  
**Don't hesitate to contact me if you have any questions or suggestions.**
