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

    def msg_perdedor(palavra_secreta):
        print("Puxa, você foi enforcado!")
        print("A palavra era {}".format(palavra_secreta))
        print("    _______________         ")
        print("   /               \       ")
        print("  /                 \      ")
        print("//                   \/\  ")
        print("\|   XXXX     XXXX   | /   ")
        print(" |   XXXX     XXXX   |/     ")
        print(" |   XXX       XXX   |      ")
        print(" |                   |      ")
        print(" \__      XXX      __/     ")
        print("   |\     XXX     /|       ")
        print("   | |           | |        ")
        print("   | I I I I I I I |        ")
        print("   |  I I I I I I  |        ")
        print("   \_             _/       ")
        print("     \_         _/         ")
        print("       \_______/           ")

    def msg_vencedor():
        print("Parabéns, você ganhou!")
        print("       ___________      ")
        print("      '._==_==_=_.'     ")
        print("      .-\\:      /-.    ")
        print("     | (|:.     |) |    ")
        print("      '-|:.     |-'     ")
        print("        \\::.    /      ")
        print("         '::. .'        ")
        print("           ) (          ")
        print("         _.' '._        ")
        print("        '-------'       ")
    
    def desenha_forca(erros):
        print("  _______     ")
        print(" |/      |    ")

        if erros == 1:
            print(" |      (_)   ")
            print(" |            ")
            print(" |            ")
            print(" |            ")

        if erros == 2:
            print(" |      (_)   ")
            print(" |      \     ")
            print(" |            ")
            print(" |            ")

        if erros == 3:
            print(" |      (_)   ")
            print(" |      \|    ")
            print(" |            ")
            print(" |            ")

        if erros == 4:
            print(" |      (_)   ")
            print(" |      \|/   ")
            print(" |            ")
            print(" |            ")

        if erros == 5:
            print(" |      (_)   ")
            print(" |      \|/   ")
            print(" |       |    ")
            print(" |            ")

        if erros == 6:
            print(" |      (_)   ")
            print(" |      \|/   ")
            print(" |       |    ")
            print(" |      /     ")

        if erros == 7:
            print(" |      (_)   ")
            print(" |      \|/   ")
            print(" |       |    ")
            print(" |      / \   ")

        print(" |            ")
        print("_|___         ")
        print()

    palavra_escolhida, letras_ocultas = escolhe_palavra(escolhe_tema) 
    # palavra_escolhida é a palavra sorteada para o úsuario
    # palavras ocultas é a palavra que será mostra para o usuario em forma de _
    


    erros = 0
    print(palavra_escolhida)


    while True:
        chuta_letra = input('Escolhe uma letra:')
        chuta_letra = chuta_letra.upper() #separa as letrasda string

        index = 0

        
        for letra in palavra_escolhida:
            if letra.upper() == chuta_letra:
                letras_ocultas[index] = chuta_letra
            index += 1
        print(letras_ocultas)
        
        if chuta_letra.upper() not in palavra_escolhida.upper():
            erros += 1
        desenha_forca(erros)
        print(erros)
        print(letras_ocultas)

        if  erros == 7:
            msg_perdedor(palavra_escolhida)
            break
        elif "_" not in letras_ocultas:
            msg_vencedor()
            break
        else:
            continue
        
        