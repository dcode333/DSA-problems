# SP20-BCS-135 LAB TERMINAL AI
import random

# Equation to Solve,


def fitnessEquation(x, y):
    return 2 * x ** 3 + 7 * y - 147


def geneticAlgo():

    data = {
        "population": 50,
        "generations": 1000
    }

    # creating initial population
    population = []
    for i in range(data["population"]):
        individual = [random.uniform(-100, 100), random.uniform(-100, 100)]
        population.append(individual)

    # evolving population
    for i in range(data["generations"]):
        # evaluating fitness of each
        fitness = []
        for individual in population:
            x, y = individual
            fitness.append(fitnessEquation(x, y))

        # selecting individuals for breeding
        parents = []
        for i in range(int(data["population"]/2)):
            parent1 = population[fitness.index(min(fitness))]
            fitness.pop(fitness.index(min(fitness)))
            parents.append(parent1)

        # breeding next generation
        children = []
        for i in range(int(data["population"]/2)):
            child = []
            for j in range(2):
                parent = random.choice(parents)
                child.append(parent[j])
            children.append(child)

        # mutation
        for i in range(int(data["population"]/2)):
            mutation_rate = 0.1
            if random.random() <= mutation_rate:
                children[i][0] += random.uniform(-1, 1)
                children[i][1] += random.uniform(-1, 1)

        # the new population is the union of the parents and the children
        population = parents + children

    fitness = []
    for individual in population:
        x, y = individual
        fitness.append(fitnessEquation(x, y))
    Solution = population[fitness.index(min(fitness))]
    bestFitness = min(fitness)

    return Solution, bestFitness


Solution, bestFitness = geneticAlgo()

# results
print("\nSolution : ", Solution)
print("Best fitness : ", bestFitness, "\n")
