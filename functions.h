
void limparTela() {
    system("cls");
}
void menuInicial();

void inicia_tabuleiro (char tabuleiro[10][10],char mascara[10][10]) {

    for(int i = 0; i < 10 ; i++){
        for(int j = 0; j < 10; j++){
           tabuleiro[i][j] = 'A';
           mascara[i][j] = 'X';
        }
        cout << "\n";
    }
}

void exibe_tabuleiro (char tabuleiro[10][10],char mascara[10][10]) {

    for (int i = 0; i < 10; i++){
        if(i == 0){
            cout << "  ";
        }
        cout << i << " ";
    }
    cout << "\n";

    for(int i = 0; i < 10 ; i++){
        cout << i << " " ;
        for(int j = 0; j < 10; j++){
           cout << mascara[i][j] << " ";
        }
        cout << "\n";
    }
     cout << "\n\n";
     int condi = 0;

     if( condi == 1) {
        for(int i = 0; i < 10 ; i++){
        for(int j = 0; j < 10; j++){
           cout << tabuleiro[i][j] << " ";
        }
        cout << "\n";
        }
    }
}

void posiciona_barcos(char tabuleiro[10][10]) {

    int qtd_barcos = 0;
        while (qtd_barcos < 10 ) {
            int linha = rand()%10; int coluna = rand()%10;

                if(tabuleiro[linha][coluna] == 'A'){
                    tabuleiro[linha][coluna] = 'P';
                    qtd_barcos ++;
                }
        }
        qtd_barcos = 0;
        while (qtd_barcos < 7 ) {
            int linha = rand()%10; int coluna = rand()%10;

                if(tabuleiro[linha][coluna] == 'A'){
                    tabuleiro[linha][coluna] = 'M';
                    qtd_barcos ++;
                }
        }
        qtd_barcos = 0;
        while (qtd_barcos < 5 ) {
            int linha = rand()%10; int coluna = rand()%10;

                if(tabuleiro[linha][coluna] == 'A'){
                    tabuleiro[linha][coluna] = 'G';
                    qtd_barcos ++;
                }
        }
}

void pontos (char tabuleiro[10][10],int linha,int coluna,int *pontos,string *MSG) {
    switch(tabuleiro[linha][coluna]){
            case 'P':
                *MSG = "\nAcertou um barco Pequeno! (5 pts)\n";
                *pontos += 5;
                break;
            case 'M':
                 *MSG = "\nAcertou um barco Medio! (7 pts)\n";
                *pontos += 7;
                break;
            case 'G':
                *MSG = "\nAcertou um barco Grande! (10 pts)\n";
                *pontos += 10;
                break;
            default:
                 *MSG = "\nErrou o tiro\n";
                 *pontos -= 4;
                break;
            }
}

void jogo(string nome){

    char tabuleiro[10][10]; char mascara[10][10];

    inicia_tabuleiro(tabuleiro,mascara);

    posiciona_barcos(tabuleiro);

    int linha,coluna;
    int estado_do_jogo = 1 ;                        // 1 = andamento , 0 = fim do jogo
    int pontuacao = 0;
    string MSG = "";
    int tentativas = 0;
    int max_tentativas = 3;
    int opcao;

    while (tentativas < max_tentativas){

        limparTela();

        exibe_tabuleiro(tabuleiro,mascara);
        cout << "\nTentativas restantes: " << max_tentativas-tentativas << "\n";
        cout << "\nPontos : " << pontuacao << "\n";
        cout << MSG << "\n";
        cout <<"\n"<< nome <<"\nDigite uma Linha: ";
        cin >> linha;
        cout << "\nDigite uma Coluna: ";
        cin >> coluna;

        pontos(tabuleiro,linha,coluna, &pontuacao,&MSG);

        //revela a poição no tabuleiro
        mascara[linha][coluna] = tabuleiro[linha][coluna];

        tentativas++;
    }
    limparTela();
    cout << "\nFim de jogo \n";
    cout << "Deseja reiniciar ou sair? \n";
    cout << "1 - jogar novamente \n";
    cout << "2 - ir para Menu \n";
    cout << "3 - Sair \n";
    cin >> opcao;

    switch (opcao){
    case 1:
        jogo(nome);
        break;
    case 2:
        menuInicial();
        break;
        }

}

void menuInicial() {
    int opcao = 0;
    string nome = "";
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
             cout << "Digite seu nome: ";
            cin >> nome;
            limparTela();
            cout << "Jogo iniciado! \n\n";
            jogo(nome);
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
