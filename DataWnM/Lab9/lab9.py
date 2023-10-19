import pyfpgrowth as fp

def read_transactions(filename):
    transactions = []
    with open(filename, 'r') as file:
        for line in file:
            items = line.strip().split()
            transactions.append(items)
    return transactions

def find_association_rules(transactions, min_support, min_confidence):
    ffp = fp.find_frequent_patterns(transactions, min_support)
    association = fp.generate_association_rules(ffp, min_confidence)
    return association

def print_association_rules(association):
    for antecedent, (consequent, confidence) in association.items():
        strante = ','.join(antecedent)
        strcons = ','.join(consequent)
        print(f"{strante} -> {strcons} (Confidence: {round(confidence,3)})")

transactions = read_transactions('C:\\Users\\adivi\\Documents\\GitHub\\practiceprograms\\DataWnM\\Lab9\\transactions3.txt')
total_transactions = len(transactions)
min_support = total_transactions * 0.3
min_confidence = 0.4
association = find_association_rules(transactions, min_support, min_confidence)
print_association_rules(association)
