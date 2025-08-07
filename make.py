#!/usr/bin/env python3

import os
import sys
import shutil
from pathlib import Path

def create_problem(contest, problem):
    """Create a new problem file from template"""
    
    # Check if template exists
    template_path = Path("template.cpp")
    if not template_path.exists():
        print("Error: template.cpp not found in current directory")
        return False
    
    # Create paths
    problems_dir = Path("problems")
    contest_dir = problems_dir / contest
    problem_file = contest_dir / f"{problem}.cpp"
    
    # Create directories
    contest_dir.mkdir(parents=True, exist_ok=True)
    
    # Check if file already exists
    if problem_file.exists():
        response = input(f"File {problem_file} already exists! Overwrite? (y/N): ")
        if response.lower() != 'y':
            print("Cancelled.")
            return False
    
    # Copy template to new file
    shutil.copy2(template_path, problem_file)
    
    print(f"Created {problem_file}")
    print(f"Problem: Codeforces {contest}{problem}")
    print("Ready to solve!")
    return True

def show_help():
    """Show usage information"""
    print("Codeforces Problem Generator")
    print()
    print("Usage:")
    print("  python make.py <contest> <problem>")
    print("  python make.py 1234 A")
    print()
    print("Examples:")
    print("  python make.py 1789 B    # Creates problems/1789/B.cpp")
    print("  python make.py 456 C     # Creates problems/456/C.cpp")

def main():
    if len(sys.argv) != 3:
        show_help()
        sys.exit(1)
    
    contest = sys.argv[1]
    problem = sys.argv[2].upper()  # Convert to uppercase
    
    # Validate inputs
    if not contest.isdigit():
        print("Error: Contest number must be numeric")
        sys.exit(1)
    
    if not problem.isalpha() or len(problem) != 1:
        print("Error: Problem must be a single letter")
        sys.exit(1)
    
    create_problem(contest, problem)

if __name__ == "__main__":
    main() 