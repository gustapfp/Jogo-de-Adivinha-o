from random import randrange

print('**************************')
print('****Jodo de Advinhação****')
print('**************************')

numero_sorteado = randrange(0 , 101) # numero aleatório de 0 a 100 
print(numero_sorteado)
nivel = int(input('Qual nivel você deseja jogar? Fácil(1), Médio(2), Difícil(3)')) # Faz uma pergunta ao usuario

def dificuldade(seleção_de_dificuldade_do_usuario):
    if seleção_de_dificuldade_do_usuario == 1: # caso a resposta seja 1 o nivel fácil é selecionado e o usuario tem 10 tentativas
        return 10
    if seleção_de_dificuldade_do_usuario == 2: # caso a resposta seja 1 o nivel Médio é selecionado e o usuario tem 5 tentativas
        return 5
    if seleção_de_dificuldade_do_usuario == 3: # caso a resposta seja 3 o nivel Difícil é selecionado e o usuario tem 3 tentativas
        return 3

        
numero_de_chances = dificuldade(nivel)
rodada = 1
while True: 
    tentativa_do_usuario = int(input('Chute um numero de 0 a 100:'))
    if rodada >= numero_de_chances: # se o numero de rodadas for maior que o numero de chances o jogo para 
        print(f'Você ultrapassou o número de tentativas sua pontuação foi igual a 0 e o número a ser advinhado era {numero_sorteado}')
        break
    elif numero_sorteado == tentativa_do_usuario:
        print(f'Parabéns! Você acertou o número secreto! Você levou {rodada} rodadas para acertar')
        break
    else:  # se o numero de rodadas for menor que o numero de chances
        rodada += 1
        print(f'Você está na rodada {rodada} e ainda tem {numero_de_chances - rodada} chances de acertar')