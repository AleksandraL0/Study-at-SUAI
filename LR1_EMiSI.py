import numpy as np
import random, time
import matplotlib.pyplot as plt
from math import exp, log10, sin, pi

MIN_VALUE = 0


class Individual:
    def __init__(self, newChromosome):
        self.chromosome = newChromosome

    def getChromosome(self):
        return self.chromosome

    def setChromosome(self, value):
        self.chromosome = value

def f(x):
    return (exp(-2 * log10(2) * ((x - .08) / .854) ** 2)) * sin(5 * pi * (x ** (3/4) - .05)) ** 6

def check(Fmin):
    if np.fabs(Fmin - MIN_VALUE) <= 0.001:
        return True
    else:
        return False

def FitnessFunction(population):
    populationUpdate = []
    for elem in population:
        populationUpdate.append(f(elem.getChromosome()))
    sumF = 0

    # расчет Fsum
    for elem in populationUpdate:
        sumF += elem
    pValue = []
    for elem in populationUpdate:
        pValue.append(elem / sumF)
    return pValue

def crossover(parent1, parent2):
    # плоский кроссовер
    c1, c2 = parent1.getChromosome(), parent2.getChromosome()
    H1 = Individual(random.uniform(c1, c2))
    return H1


def euclidean_distance(x, y):
    p = x.getChromosome()
    q = y.getChromosome()
    return np.sum(np.square(p - q))


def plot(population, pok):
    fvalue = []
    for i in population:
        fvalue.append(f(i.getChromosome()))

    x = np.linspace(0, 1, 500)
    y = [f(i) for i in x]
    x_population = [i.getChromosome() for i in population]
    y_population = [f(i) for i in x_population]

    plt.plot(x, y, 'g')
    plt.plot(x_population, y_population, 'ro')
    title = "Поколение " + str(pok)
    plt.title(title)
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.show()


def GeneticAlgorithm(numPopulation, maxTime):
    population = []
    pok = 1
    M = numPopulation // 10
    Cf = 3
    # генерация начальной популяции
    for i in range(numPopulation):
        x = random.uniform(0, 1)
        population.append(Individual(x))

    fvalue = []
    for i in population:
        fvalue.append(f(i.getChromosome()))
    flag = False

    plot(population, 1)

    while not flag:
        pvalue = FitnessFunction(population)

        # отбор родителей
        parents = random.choices(population, weights=pvalue, cum_weights=None, k=M)

        # кроссовер
        childs = []
        for i in range(M):
            parent1, parent2 = random.sample(parents, k=2)
            child = crossover(parent1, parent2)
            childs.append(child)

        # оператор мутации над потомками
        for i in range(len(childs)):
            childs.pop(i)
            temp = random.uniform(0, 1)
            childs.insert(i, Individual(temp))

        # случайный выбор Cf родителей
        parents_cf = random.sample(parents, k=Cf)
        parents = list(set(parents) - set(parents_cf))

        # уплотнение с ограниченным турниром
        for i in range(M):
            temp = []
            idx = [i for i in range(Cf)]
            for j in range(Cf):
                temp.append(euclidean_distance(parents_cf[j], childs[i]))
            ans = sorted(zip(temp, idx), key=lambda elem: elem[0])
            id = ans[0][1]
            pmin = parents_cf[id]
            if FitnessFunction([childs[i]])[0] > FitnessFunction([pmin])[0]:
                parents_cf[id] = childs[i]

        population = parents + parents_cf

        pok += 1
        if flag or pok % 10 == 0:
            plot(population, pok)

        if pok == maxTime:
            flag = True

def analysis():
    x, y = [], []
    for num in range(10, 100+1, 10):
        x.append(num)
        y.append(GeneticAlgorithm(num, 2, 0.5, 0.001, 100))

    t = [i[0] for i in y]
    pok = [i[1] for i in y]
    scale = [i[2] for i in y]
    plt.subplot(221)
    plt.plot(x,t)
    plt.xlabel("Число особей")
    plt.ylabel("Время поиска решения, сек")

    plt.subplot(222)
    plt.plot(x,pok)
    plt.xlabel("Число особей")
    plt.ylabel("Число поколений")

    plt.subplot(223)
    plt.plot(x,scale)
    plt.xlabel("Число особей")
    plt.ylabel("Точность нахождения решения, %")
    plt.show()

    x_Cross, x_Mul, y = [], [], []
    num = 100
    pCross = 0.1
    while pCross < 1:
        x_Cross.append(pCross)
        y.append(GeneticAlgorithm(num, 2, pCross, 0.001, 100))
        pCross += 0.2

    t_pCross = [i[0] for i in y]
    pok_pCross = [i[1] for i in y]
    scale_pCross = [i[2] for i in y]

    pMul = 0.001
    y = []
    while pMul < .1:
        x_Mul.append(pMul)
        y.append(GeneticAlgorithm(num, 2, 0.5, pMul, 100))
        pMul += 0.005

    t_pMul = [i[0] for i in y]
    pok_pMul = [i[1] for i in y]
    scale_pMul = [i[2] for i in y]

    plt.subplot(331)
    plt.plot(x_Cross,t_pCross)
    plt.xlabel("Вероятность кроссинговера")
    plt.ylabel("Время поиска решения, сек")

    plt.subplot(332)
    plt.plot(x_Cross,pok_pCross)
    plt.xlabel("Вероятность кроссинговера")
    plt.ylabel("Число поколений")

    plt.subplot(333)
    plt.plot(x_Cross,scale_pCross)
    plt.xlabel("Вероятность кроссинговера")
    plt.ylabel("Точность нахождения решения, %")

    plt.subplot(334)
    plt.plot(x_Mul,t_pMul)
    plt.xlabel("Вероятность мутации")
    plt.ylabel("Время поиска решения, сек")

    plt.subplot(335)
    plt.plot(x_Mul,pok_pMul)
    plt.xlabel("Вероятность мутации")
    plt.ylabel("Число поколений")

    plt.subplot(336)
    plt.plot(x_Mul,scale_pMul)
    plt.xlabel("Вероятность мутации")
    plt.ylabel("Точность нахождения решения, %")
    plt.show()

#analysis()


if __name__ == '__main__':
    GeneticAlgorithm(1000, 30)

