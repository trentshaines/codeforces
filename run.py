#!/usr/bin/env python3

import os
import sys
import subprocess
from pathlib import Path

def compile_and_run(contest, problem, compile_only=False):
    """Compile and run a problem (runs by default unless compile_only is True)"""
    
    # Create paths
    problem_dir = Path("problems") / contest
    cpp_file = problem_dir / f"{problem}.cpp"
    exe_file = problem_dir / problem
    
    # Check if source file exists
    if not cpp_file.exists():
        print(f"Error: {cpp_file} not found")
        return False
    
    # Compile
    print(f"Compiling {cpp_file}...")
    result = subprocess.run([
        "g++", "-o", str(exe_file), str(cpp_file)
    ], capture_output=True, text=True)
    
    if result.returncode != 0:
        print("Compilation failed:")
        print(result.stderr)
        return False
    
    print(f"✅ Compiled successfully: {exe_file}")
    
    # Run automatically unless compile_only is specified
    if not compile_only:
        print(f"Running {exe_file}...")
        print("=" * 40)
        subprocess.run([str(exe_file)])
        print("=" * 40)
    
    return True

def show_help():
    print("Codeforces Compiler & Runner")
    print()
    print("Usage:")
    print("  python run.py <contest> <problem> [compile]")
    print()
    print("Examples:")
    print("  python run.py 50 A           # Compile and run (default)")
    print("  python run.py 50 A compile   # Just compile, don't run")
    print("  python run.py 1789 B         # Compile and run")

def main():
    if len(sys.argv) < 3:
        show_help()
        sys.exit(1)
    
    contest = sys.argv[1]
    problem = sys.argv[2].upper()
    compile_only = len(sys.argv) > 3 and sys.argv[3].lower() == "compile"
    
    compile_and_run(contest, problem, compile_only)

if __name__ == "__main__":
    main() 