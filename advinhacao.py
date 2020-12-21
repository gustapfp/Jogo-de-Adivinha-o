from random import randrange

print('**************************')
print('****Jodo de Advinhação****')
print('**************************')

numero_sorteado = randrange(0 , 101) # numero aleatório de 0 a 100 
print(numero_sorteado)
numero_de_chances = int(input('Quantas tentativas você quer?')) # Faz uma pergunta ao usuario
rodada = 0 
while True: 
    tentativa_do_usuario = int(input('Chute um numero de 0 a 100:'))
    if rodada >= numero_de_chances: # se o numero de rodadas for maior que o numero de chances o jogo para 
        print('Você ultrapassou o número de tentativas')
        break
    elif numero_sorteado == tentativa_do_usuario:
        print(f'Parabéns! Você acertou o número secreto! Você levou {rodada} rodadas para acertar')
        break
    else:  # se o numero de rodadas for menor que o numero de chances
        rodada += 1
        print(f'Você está na rodada {rodada} e ainda tem {numero_de_chances - rodada} chances de acertar')