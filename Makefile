# Fichier Makefile racine
# Cette variable contient la liste des sous répertoires
# pour lesquels il faudra construire un programme.
# Pour l instant, seul le serveur web est dans la liste.
FOLDERS = webserver

# Indique à make les règles qui ne correspondent pas à la création
# d un fichier
# make lancera toujours la construction de cette regle si elle est
# demandee, même si un fichier/repertoire du nom de la cible existe
# On indique ici la regle all ainsi que les repertoires
. PHONY : all $ ( FOLDERS )

# La regle qui sera executee si on lance make sans argument
all : $ ( FOLDERS )

# Cette regle va lancer make dans le répertoire webserver
# option -C de make
webserver :
make -C webserver
