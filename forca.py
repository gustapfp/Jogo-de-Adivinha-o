from random import randint

def jogar():
    print('***************************')
    print('*******Jodo da Forca*******')
    print('***************************')

    escolhe_tema = int(input("Escolha um tema: Animais(1), Frutas(2), Objetos de Casa(3), Tema Aletorio(4)"))


    animais = ["abelha", "canguru", "girafa", "leopardo", "leão", "macaco", "lontra", "panda", "urso polar", "rinoceronte", "tigre", "tartaruga", "morsa", "zebra"]
    frutas = ["Abacaxi", "Açaí", "Banana", "Maça", "Laranja", "Pera", "Morango", "uva", "cocô"]
    objetos_de_casa = ["Televisão", "Fogão" ,"Geladeira", "Mesa",  "cadeira", "Armários", "Microondas", "Batedeira", "Liquidificador"]
    aleatorio = ["abelha", "canguru", "girafa", "leopardo", "leão", "macaco", "lontra", "panda", "urso polar", "rinoceronte", "tigre", "tartaruga", "morsa", "zebra", "Abacaxi", "Açaí", "Banana", "Maça", "Laranja", "Pera", "Morango", "uva", "cocô", "Televisão", "Fogão" ,"Geladeira", "Mesa",  "cadeira", "Armários", "Microondas", "Batedeira", "Liquidificador"]
    
    
    def oculta_palavra(palavra): # oculta a palavra sorteada para o jogador
        tamanho_da_palavra = int(len(palavra))
        letras = ["_" for i in range(tamanho_da_palavra)]

        return letras


    def escolhe_palavra(tema_do_usuario): # sorteia uma palavra para o jogador
        if tema_do_usuario == 1: 
            palavra_escolhida = animais[randint(0, len(animais)-1)]
            return palavra_escolhida, oculta_palavra(palavra_escolhida)
        elif tema_do_usuario == 2:
            palavra_escolhida = frutas[randint(0, len(frutas)-1)]
            return palavra_escolhida, oculta_palavra(palavra_escolhida)      
        elif tema_do_usuario == 3:
            palavra_escolhida = objetos_de_casa[randint(0, len(objetos_de_casa)-1)]
            return palavra_escolhida, oculta_palavra(palavra_escolhida)
        elif tema_do_usuario == 4:
            palavra_escolhida = aleatorio[randint(0, len(aleatorio)-1)]
            return palavra_escolhida, oculta_palavra(palavra_escolhida)

    # def check_palavra_secreta(palavra): # checa se todas as letras escondidas ja foram encontradas
    #     if "_" in palavra:
    #         return True
    #     elif rodadas == 0:
    #         return False
    #     elif  "_" not in letras_ocultas:
    #         return False

    palavra_escolhida, letras_ocultas = escolhe_palavra(escolhe_tema) 
    tamanho_da_palavra = int(len(palavra_escolhida))
    # palavra_escolhida é a palavra sorteada para o úsuario
    # palavras ocultas é a palavra que será mostra para o usuario em forma de _
    


    rodadas = 6
    print(palavra_escolhida)

    x = True
    while x == True:         
        if rodadas <= 0:
            x = False
            print(letras_ocultas)
        elif  "_" not in letras_ocultas:
            x = False
            print(letras_ocultas)
        else:
            print(letras_ocultas)
            chuta_letra = input('Escolhe uma letra:')
            for i in range(tamanho_da_palavra):
                if palavra_escolhida[i] == chuta_letra:
                    letras_ocultas[i] = chuta_letra
        




        #check_palavra_secreta(letras_ocultas)

        
        