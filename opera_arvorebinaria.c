//percorre a arvore contando os nós folha
int ptrContaNosFolhaRec (NoArvore *ptrRaiz)
{
    int contador = 0;

        if(!ptrRaiz->ptrEsq && !ptrRaiz->ptrDir) ///testamos se os proximos nós são nulos se sim, chegamos a um nó folha
           return 1;

        else ///caso hajam mais sub-arvores a função irá caminhar por elas
        {
           contador = ptrContaNosFolhaRec(ptrRaiz->ptrEsq);
           contador += ptrContaNosFolhaRec(ptrRaiz->ptrDir);
           return contador;
        }
}

int ContaNosFolha (Arvore *ptrArvore)
{
    ptrContaNosFolhaRec(NoArvore *ptrRaiz);

    return ptrContaNosFolhaRec (ptrArvore->ptrRaiz);
}

//espelha arvore binaria
void EspelhaArvoreBinariaRec(NoArvore *ptrRaiz)
{
    if(ptrRaiz)
    {
        NoArvore *ptrAux;
        ///passa os valores da raiz para o aux
        ptrAux->ptrEsq = ptrRaiz->ptrDir;
        ptrAux->ptrDir = ptrRaiz->ptrEsq;
        ptrAux->ptrPai = ptrRaiz->ptrPai;
        ptrAux->ptrDado = ptrRaiz->ptrDado;

        ///caminha ate o ultimo no em cada direção
        if(ptrRaiz->ptrEsq)
        {
            EspelhaArvoreBinariaRec(ptrRaiz->ptrEsq);///altera os ponteiros
        }
        if(ptrRaiz->ptrDir)
        {
            EspelhaArvoreBinariaRec(ptrRaiz->ptrDir);///altera os ponteiros
        }

        ptrRaiz = ptrAux; ///passa a alteração para a raiz em cada nível
    }
}
void EspelhaArvoreBinaria(Arvore *ptrArvore)
{
    EspelhaArvoreBinariaRec(NoArvore *ptrRaiz);
}


//verifica se duas arvores binarias são iguais
int ComparaArvoreBinariaRec(NoArvore* ptrRaiz1,NoArvore* ptrRaiz2,
                            int(*ptrFncCompara)(void* ptrRaiz1->dado,void* ptrRaiz2->dado),
                            int (*ptrFncEscreve)(void* aux));
{
    if(!ptrFncCompara(void* ptrRaiz1->dado,void* ptrRaiz2->dado))///Se compara = 0 os elementos são iguais
            {
                if(ptrRaiz1->ptrEsq && ptrRaiz2->ptrEsq)///evita que a função reconheça nós folha como iguais
                ///caminha pela sub-Arvore esquerda das duas árvores
          	 ComparaArvoreBinariaRec(NoArvore* ptrRaiz1->Esq,NoArvore* ptrRaiz2->Esq,
                                        int(*ptrFncCompara)(void* ptrRaiz1->ptrEsq->ptrDado,void* ptrRaiz2->ptrEsq->ptrDado));
                if(ptrRaiz1->ptrDir && ptrRaiz2->ptrDir)///evita que a função reconheça nós folha como iguais
                ///caminha pela sub-Arvore direita da duas arvores
                ComparaArvoreBinariaRec(NoArvore* ptrRaiz1->Dir,NoArvore* ptrRaiz2->Dir,
                                        int(*ptrFncCompara)(void* ptrRaiz1->ptrDir->ptrDado,void* ptrRaiz2->ptrDir->ptrDado));
            }
            else
            {
                ptrFncEscreve (ptrRaiz1->ptrDado);
                ptrFncEscreve (ptrRaiz2->ptrDado);
                return ptrFncCompara();
            }

}
int ComparaArovreBinaria(Arvore *ptrArvore1, Arvore *ptrArvore2)
{
    return ComparaArovreBinariaRec(ptrArvore1->ptrRaiz, ptrArvore2->ptrRaiz, ptrArvore->ptrFncCompara);
}

//escreve valores duplicados na arvore
int ptrContaNosFolhaRec (NoArvore *ptrRaiz)
{
    int contador = 0;

        if(!ptrRaiz->ptrEsq && !ptrRaiz->ptrDir) ///testamos se os proximos nós são nulos se sim, chegamos a um nó folha
           return 1;

        else ///caso hajam mais sub-arvores a função irá caminhar por elas
        {
           contador = ptrContaNosFolhaRec(ptrRaiz->ptrEsq);
           contador += ptrContaNosFolhaRec(ptrRaiz->ptrDir);
           return contador;
        }
}

int ContaNosFolha (Arvore *ptrArvore)
{
    ptrContaNosFolhaRec(NoArvore *ptrRaiz);

    return ptrContaNosFolhaRec (ptrArvore->ptrRaiz);
}


/// percorre árvore procurando por um elemento (subRaiz) que contenha um valor igual ao de ptrRaiz
void EscreveArovreBinariaDuplicadoRec_SubRaiz(NoArvore *ptrRaiz, NoArvore *ptrSubRaiz,
                                            int (*ptrFncCompara)(void*, void*),
                                            void (*ptrFncEscreve)(void *ptrElemento))
{
    ///imprime o dado em tela caso eles sejam iguais
    if(!ptrFncCompara(ptrRaiz->ptrDado,ptrSubRaiz->ptrDado))
        ptrFncEscreve(ptrSubRaiz->ptrDado);

    ///varia a subraiz faz a comparação de maneira recursiva
        if(ptrSubRaiz->ptrEsq)
            EscreveArovreBinariaDuplicadoRec_SubRaiz(ptrRaiz,ptrSubRaiz->ptrEsq,ptrFnCompara(),ptrFncEscreve());
        if(ptrSubRaiz->ptrDir)
            EscreveArovreBinariaDuplicadoRec_SubRaiz(ptrRaiz,ptrSubRaiz->ptrDir,ptrFnCompara(),ptrFncEscreve());

}
/// caminha pela árvore variando o nó ptrRaiz e para cada um chama a rotina anterior
void EscreveArovreBinariaDuplicadoRec_Raiz(NoArvore *ptrRaiz, NoArvore *ptrSubRaiz,
                                           int (*ptrFncCompara)(void*, void*), void (*ptrFncEscreve)(void *ptrElemento))
{
    if(ptrRaiz)
    {
        ///se houver uma raiz variamos a subraiz para averiguar se o dado esta repetido
        EscreveArovreBinariaDuplicadoRec_SubRaiz(ptrRaiz, ptrRaiz, ptrFncCompara, ptrFncEscreve);

        ///se o nó tiver filhos testamos se eles se repetem
        if(ptrRaiz->ptrEsq)
            EscreveArovreBinariaDuplicadoRec_Raiz(ptrRaiz->ptrEsq,ptrRaiz,ptrFncCompara,ptrFncEscreve);
        if(ptrRaiz->ptrDir)
            EscreveArovreBinariaDuplicadoRec_Raiz(ptrRaiz->ptrDir,ptrRaiz,ptrFncCompara,ptrFncEscreve);
    }


}
void EscreveArovreBinariaDuplicado(Arvore *ptrArvore)
{
    EscreveArovreBinariaDuplicadoRec_Raiz(ptrArvore->ptrRaiz, ptrArvore->ptrRaiz,
                                          ptrArvore->ptrFncCompara, ptrArvore->ptrFncEscreve);
}
