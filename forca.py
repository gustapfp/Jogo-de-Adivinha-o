from random import randint

#def jogar():
print('***************************')
print('*******Jodo da Forca*******')
print('***************************')

escolhe_tema = int(input("Escolha um tema: Animais(1), Frutas(2), Objetos de Casa(3), Tema Aletorio(4)"))


animais = ["abelha", "canguru", "girafa", "leopardo", "leão", "macaco", "lontra", "panda", "urso polar", "rinoceronte", "tigre", "tartaruga", "morsa", "zebra"]
frutas = ["Abacaxi", "Açaí", "Banana", "Maça", "Laranja", "Pera", "Morango", "uva", "cocô"]
objetos_de_casa = ["Televisão", "Fogão" ,"Geladeira", "Mesa",  "cadeira", "Armários", "Microondas", "Batedeira", "Liquidificador"]
aleatorio = ["abelha", "canguru", "girafa", "leopardo", "leão", "macaco", "lontra", "panda", "urso polar", "rinoceronte", "tigre", "tartaruga", "morsa", "zebra", "Abacaxi", "Açaí", "Banana", "Maça", "Laranja", "Pera", "Morango", "uva", "cocô", "Televisão", "Fogão" ,"Geladeira", "Mesa",  "cadeira", "Armários", "Microondas", "Batedeira", "Liquidificador"]

def escolhe_palavra(tema_do_usuario):
    
    if tema_do_usuario == 1: 
        palavra_escolhida = animais[randint(0, len(animais))]
        return palavra_escolhida
    elif tema_do_usuario == 2:
        palavra_escolhida = frutas[randint(0, len(frutas))]
        return palavra_escolhida      
    elif tema_do_usuario == 3:
        palavra_escolhida = objetos_de_casa[randint(0, len(objetos_de_casa))]
        return palavra_escolhida
    elif tema_do_usuario == 4:
        palavra_escolhida = aleatorio[randint(0, len(aleatorio))]
        return palavra_escolhida

print(escolhe_palavra(escolhe_tema))