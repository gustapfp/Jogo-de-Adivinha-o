import advinhacao
import advinhacao_com_dicas
import forca

print("Olá! Seja bem vindo ao jogo de advinhação. Escolha um modo de jogo:")
print("Advinhação com dicas(1)")
print("Advinhação sem dicas(2)")
print("Forca (3)")

jogo_escolhido = int(input("Jogo escolhido:"))

if jogo_escolhido == 1:
    advinhacao_com_dicas.jogar()
elif jogo_escolhido == 2:
    advinhacao.jogar()
elif jogo_escolhido == 3:
    forca.jogar()
