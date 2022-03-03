
void limparTela() {
    system("cls");
}

void inicia_tabuleiro (char tabuleiro[10][10],char mascara[10][10]) {

    for(int i = 0; i < 10 ; i++){
        for(int j = 0; j < 10; j++){
           tabuleiro[i][j] = 'A';
           mascara[i][j] = '*';
        }
        cout << "\n";
    }
}

void exibe_tabuleiro (char tabuleiro[10][10],char mascara[10][10]) {

    for(int i = 0; i < 10 ; i++){
        for(int j = 0; j < 10; j++){
           cout << mascara[i][j] << " ";
        }
        cout << "\n";
    }
}

void jogo(){

    char tabuleiro[10][10]; char mascara[10][10];

    inicia_tabuleiro(tabuleiro,mascara);
    exibe_tabuleiro(tabuleiro,mascara);

    int linha,coluna;
    int estado_do_jogo = 1 ;                        // 1 = andamento , 0 = fim do jogo


    while (estado_do_jogo == 1){

        limparTela();

        exibe_tabuleiro(tabuleiro,mascara);

        cout << "\nDigite uma Linha: ";
        cin >> linha;
        cout << "\nDigite uma Coluna: ";
        cin >> coluna;

        //revela a poição no tabuleiro
        mascara[linha][coluna] = tabuleiro[linha][coluna];



    }

}


void menuInicial() {
    int opcao = 0;
    while (opcao < 1 || opcao > 3) {
        limparTela();
        cout << "Bem vindo ao jogo da forca!\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opção: ";

        cin >> opcao;

        switch (opcao) {
        case 1:
            limparTela();
            cout << "Jogo iniciado! \n\n";
            jogo();
            break;
        case 2:
            limparTela();
            cout << "Sobre o jogo: \n";
            break;
        case 3:
            limparTela();
            cout << "Saindo... \n";
            break;
        }
    }
}
