<h1 align="center"> Equilibrador PID (WIP) </h1>

![ALOW](Imagens/Logo.PNG)

# Introdução
Projeto que visa explorar o funcionamento e aplicabilidade do sistema de controle PID, para isso o objetivo do mesmo será controlar a posição de uma bolinha, a qual será equilibrada em uma barra.

# Esboço da Estrutura Física
<div align="center">  
  <h3>Esboço Inicial</h3>
  <img src="https://github.com/osmar-candido/Equilibrador-PID/blob/32d471ab13c34fbf4f6023804e4090dc3f51ee7b/Imagens/Esbo%C3%A7oSemMedidas.jpg" width="400">
  
  <h3>Esboço com Medidas</h3>
  <img src="https://github.com/osmar-candido/Equilibrador-PID/blob/32d471ab13c34fbf4f6023804e4090dc3f51ee7b/Imagens/Esbo%C3%A7oComMedidas.jpg" width="400">
  
  <h3 aling="left">Montagem</h3>
  <img src="https://github.com/osmar-candido/Equilibrador-PID/blob/73b7af5404ce1d5f0cc2963a7992429d506e0d20/Imagens/MontagemInicial.jpg" width="400">
</div>

# Microcontrolador
Para o controle do equipamento será utilizado um [Arduino UNO](https://store-usa.arduino.cc/products/arduino-uno-rev3?selectedStore=us) que é munido do MCU [Atmega328P](https://pdf1.alldatasheet.com/datasheet-pdf/view/241077/ATMEL/ATMEGA328P.html) que opera a 16Mhz. 
O motivo de sua escolha estão além do fator de disponibilidade, esta escolha se baseia na capacidade de processamento, seus atuadores disponíveis, facilidade de debug e o sistema nativo de comunicação Serial. Desta forma cumprindo os requisitos desejaveis para a execução do projeto. Claramente, unindo a isso a vasta comunidade já existente ao redor do mesmo o torna proprício para essa aplicação de metodologias.

# Sensores e atuadores
O controle do ângulo da barra será efetuado por um [motor de passo](https://documents.pub/document/23km-c051-07v.html) ligado por correia a barra, o motor será controlador por um driver [TB6600](https://www.mcielectronics.cl/website_MCI/static/documents/TB6600_data_sheet.pdf) que possui funções como fracionamento dos passos do motor.
Já para o sensor será utilizado o [HC-SR04](https://storage.googleapis.com/baudaeletronicadatasheet/HC-SR04.pdf) que consiste em um sensor de distância ultrassônico, o qual será responsável por identificar a distancia bolinha assim sabendo sua posição ao longo da barra.

# Metodologia
- [x] 1. Passo - `Definição dos Objetivos do Projeto`
- [x] 2. Passo - `Esboço Estrutura Inicial`
- [x] 3. Passo - `Esboço Estrutura Detalhado`
- [x] 4. Passo - `Montagem`
- [x] 5. Passo - `Alocação dos demais componentes`
- [ ] 6. Passo - `Programação`
- [ ] 7. Passo - `Conclusão`

# Método de controle
- Sistema de Primeira Ordem
- Sistema de Segunda Ordem
- Sistema Subamortecido
- Sistema Criticamente amortecido

# Lista de materiais
 - `Estrutura`
   - [Perfil de Aluminio leve v-Slot 40x40](https://loja.forsetisolucoes.com.br/perfil-estrutural-em-aluminio-40x40-basico-canal-8-t-slot-tslot)
     - Cortes: 
       -  2 un. 400mm
       -  3 un. 150mm
   - [Placa de conexão 90°](https://loja.forsetisolucoes.com.br/placa-de-conexao-montagem-90-graus-para-perfil-estrutural-em-aluminio) 1 un.
   - [Capa de fechamento frontal quadrada](https://loja.forsetisolucoes.com.br/capa-de-fechamento-frontal-quadrada-preta-para-perfil-estrutural-em-aluminio) 1 un.
   - [Polia Sincronizadora GT2 20 Dentes](https://loja.forsetisolucoes.com.br/polia-sincronizadora-gt2-em-aluminio-com-20-dentes) 2 un.
   - [Correia Sincronizadora GT2](https://loja.forsetisolucoes.com.br/correia-sincronizadora-gt2-aberta) 600mm
   - [mola Tensionadora anti folga para Correia](https://loja.forsetisolucoes.com.br/mola-tensionadora-anti-folga-para-correia-6mm) 1 un.
   - [Chapa L para Tensionamento de Correia](https://loja.forsetisolucoes.com.br/chapa-l-para-tensionamento-de-correias-gt2-5mm-e-6mm) 2 un.
   - [Apoio Ajustável emborrachado](https://www.loja.forsetisolucoes.com.br/pe-nivelador-articulado-reforcado-em-aco-rexroth) 1 un.
 - `Atuadores e Demais Componentes`
   - [Motor de Passo](https://www.saravati.com.br/motor-de-passo-nema-23-7-kgfcm-14a?utm_source=Site&utm_medium=GoogleMerchant&utm_campaign=GoogleMerchant) 1 un.
   - [Driver TB6600](https://www.piscaled.com.br/driver-motor-passo-tb67s109aftg-35a-similar-tb6600?utm_source=Site&utm_medium=GoogleMerchant&utm_campaign=GoogleMerchant&gclid=CjwKCAjwj42UBhAAEiwACIhADj5mEDsMmJBUuQFbbl36qDpT28BylLcsfpUleVGSf7WymHHi6qtKFRoCSRQQAvD_BwE) 1 un.  
   - [Bola de Tenis de Mesa](https://www.google.com/search?q=bola+tenis+de+mesa&rlz=1C1FCXM_pt-PTBR999BR999&sxsrf=ALiCzsb4lQUk771blU6INnRFCYrKUPQpnQ%3A1652788022816&ei=NouDYvXGMaCH5OUPyOq48Aw) 1 un.  
   - [Fonte Alimentação]() 1 un.  
   - [Arduino Uno]() 1 un.  
   - [Display LCD 16x2]() 1 un.  
   - [Modulo I2C para display]() 1 un.  
   - [Botão](https://pt.aliexpress.com/item/1005001865063570.html?spm=a2g0o.productlist.0.0.30387d35B8lVv0&algo_pvid=47c8a6da-a321-4caf-8b6b-58afc68bd679&algo_exp_id=47c8a6da-a321-4caf-8b6b-58afc68bd679-28&pdp_ext_f=%7B%22sku_id%22%3A%2212000017981726696%22%7D&pdp_npi=2%40dis%21BRL%21%2140.34%21%21%21%21%21%400bb0622c16521390021906905e5017%2112000017981726696%21sea) 3 un.  
