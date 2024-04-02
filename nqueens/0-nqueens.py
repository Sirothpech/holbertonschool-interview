#!/usr/bin/python3
import sys


def is_safe(x_new, y_new, queens_positions):
    """
    Vérifie si une nouvelle reine peut être placée en toute sécurité
    à la position (x_new, y_new) par rapport aux reines
    déjà placées sur l'échiquier.

    Args:
        x_new (int): Coordonnée x de la nouvelle reine.
        y_new (int): Coordonnée y de la nouvelle reine.
        queens_positions (list): Liste de tuples contenant
        les coordonnées des reines déjà placées.

    Returns:
        bool: True si la nouvelle reine peut être placée
        en toute sécurité, False sinon.
    """
    for queen_x, queen_y in queens_positions:
        if queen_x == x_new or queen_y == y_new:
            # La nouvelle reine menace une reine déjà placée
            # sur la même ligne ou la même colonne
            return False
        if abs(queen_x - x_new) == abs(queen_y - y_new):
            # La nouvelle reine menace une reine déjà placée
            # sur la même diagonale
            return False
    return True


def solve_nqueens(N, queens_positions, row=0, solutions=[]):
    """
    Résout le problème des N reines sur un échiquier de taille N x N.

    Args:
        N (int): Taille de l'échiquier et le nombre de reines à placer.
        queens_positions (list): Liste de tuples contenant
        les coordonnées des reines déjà placées.
        row (int): Ligne actuelle de l'échiquier où placer la prochaine reine.
        solutions (list): Liste pour stocker les solutions valides.

    Returns:
        list: Liste de toutes les solutions valides.
    """
    if row == N:
        solutions.append(queens_positions.copy())
    else:
        for col in range(N):
            if is_safe(row, col, queens_positions):
                queens_positions.append([row, col])
                solve_nqueens(N, queens_positions, row + 1, solutions)
                queens_positions.pop()
    return solutions


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
        if N < 4:
            print("N must be at least 4")
            sys.exit(1)
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    solutions = solve_nqueens(N, [])
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
