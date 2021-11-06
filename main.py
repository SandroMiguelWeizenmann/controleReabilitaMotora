import pyautogui
import PySimpleGUI as sg
from datetime import datetime
import serial
import os

repet = ''
amplit = ''


## SALVA OS RESULTADOS DO EXERCÍCIO ##
def salvar (nome):
    n = nome + '.pdf'
    capturar = pyautogui.screenshot()
    capturar.save(n)

## TELA PYTHON ##
class TelaPython:
    def __init__(self):
        sg.change_look_and_feel('LightBrown1')
        #Layout
        layout = [
            [sg.Text('Paciente: '), sg.Input(size=(70,0),key ='nome')],
            [sg.Text('Nº de repetições: '), sg.Input(size=(10,0),key = 'repeticao'),
             sg.Text('Amplitude: '), sg.Input(size=(10, 0), key='amplitude'),
             sg.Text('Sessão: '), sg.Input(size=(10,0),key = 'sessao')],
            {sg.Button('Iniciar Movimento'), sg.Button('Salvar Dados')},
            [sg.Text('Log. Sistema')]
            ,[sg.Output(size = (80,10))]
        ]
        #Janela
        self.janela = sg.Window("Interface Gráfica Controle Braço Robótico").layout(layout)


    def Iniciar (self):
        while True:
            self.button, self.values = self.janela.Read()
            print(self.values)
            data = str(datetime.now().strftime('%Y-%m-%d %Hh %Mm %Ss'))
            nome = self.values['nome']
            repet = self.values['repeticao']
            amplit = self.values['amplitude']
            nome = nome +' '+ data

            if self.button == 'Salvar Dados':
                salvar(nome)
                print('Arquivo salvo com sucesso')

            if self.button == 'Iniciar Movimento':
                controle = Controller()
                controle.inicializa_porta_serial()
                controle.controle(repet,amplit)



##COMUNICAÇÃO SERIAL##
class Controller:
    def __init__(self):
        # inicializa todas as variaveis de inicialização
        self.ser = None
        self.byte_recebido = ''
        self.conn = None

    def inicializa_porta_serial(self):
        try:
            # Inicialização e cofiguração da porta serial
            self.ser = serial.Serial(port='COM4',
                                     baudrate=9600,
                                     parity=serial.PARITY_NONE,
                                     stopbits=serial.STOPBITS_ONE,
                                     bytesize=8, timeout=3)
            print('Configurações da porta serial : \n', self.ser)
        except:
            print("erro ao abrir a porta serial")
        try:
            self.ser.isOpen()
            print("porta serial aberta")

        except:
            print("Erro: porta serial não esta aberta")
            exit()

    def controle(self,repet,amplit):
        os.system('clear') or None
        print('Nome do Paciente: ',self.values['nome'])
        print ('\nNúmero: de repetições: ',repet)
        print ('Amplitude do movimento:',amplit)
        print ('Inicio do Exercício: ', datetime.now().strftime('%Y-%m-%d %H:%M:%S'))

        if self.ser.isOpen():
            try:
                self.ser.write (bytes(amplit,'utf-8'))
                self.ser.write(bytes(repet, 'utf-8'))
                while True:
                    # Tenta ler oque esta na porta serial
                    try:
                        self.byte_recebido = self.ser.read().decode("ascii")
                    except:
                        print('erro na leitura da porta ou conversão')

                    if self.byte_recebido != '':
                        comando = self.byte_recebido
                        print(self.byte_recebido)
                        if comando == 'z':
                            self.ser.close()
                            print('Final do Exercício: ', datetime.now().strftime('%Y-%m-%d %H:%M:%S'))
                            print('Movimento encerrado com sucesso!')
                            break

                    else:
                        print('Aguardando comando...')
                        self.ser.close()
                        break

            except:
                print("Erro durante a execução ")
        else:
            print("Não é possível abrir a porta serial.")
            self.ser.close()

#   MAIN
if __name__ == '__main__':
    tela = TelaPython()
    tela.Iniciar()