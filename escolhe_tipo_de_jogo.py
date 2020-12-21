import advinhacao
import advinhacao_com_dicas

print("Olá! Seja bem vindo ao jogo de advinhação. Escolha um modo de jogo:")
print("Advinhação com dicas(1)")
print("Advinhação sem dicas(2)")

jogo_escolhido = int(input("Jogo escolhido:"))

if jogo_escolhido == 1:
    advinhacao_com_dicas.jogar()
elif jogo_escolhido == 2:
    advinhacao.jogar()
