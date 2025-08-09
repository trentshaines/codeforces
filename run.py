#!/usr/bin/env python3

import os
import sys
import subprocess
from pathlib import Path

def compile_and_run(contest, problem, compile_only=False, manual_input=False, input_file=None):
    """Compile and run a problem"""
    
    # Create paths
    problem_dir = Path("problems") / contest
    cpp_file = problem_dir / f"{problem}.cpp"
    exe_file = problem_dir / problem
    default_input = problem_dir / "input.txt"
    
    # Check if source file exists
    if not cpp_file.exists():
        print(f"Error: {cpp_file} not found")
        return False
    
    # Compile
    print(f"Compiling {cpp_file}...")
    result = subprocess.run([
        "g++", "-std=c++17", "-o", str(exe_file), str(cpp_file)
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
        
        if manual_input:
            # Manual input mode
            print("Manual input mode - type your input (Ctrl+D when done):")
            subprocess.run([str(exe_file)])
        elif input_file and Path(input_file).exists():
            # Specific input file
            print(f"Using input from: {input_file}")
            with open(input_file, 'r') as f:
                subprocess.run([str(exe_file)], stdin=f)
        elif default_input.exists():
            # Default input.txt file
            print(f"Using input from: {default_input}")
            with open(default_input, 'r') as f:
                subprocess.run([str(exe_file)], stdin=f)
        else:
            # No input file found, fall back to manual
            print(f"No {default_input} found - manual input mode:")
            print("Type your input (Ctrl+D when done):")
            subprocess.run([str(exe_file)])
        
        print("=" * 40)
    
    return True

def show_help():
    print("Codeforces Compiler & Runner")
    print()
    print("Usage:")
    print("  python run.py <contest> <problem> [options]")
    print()
    print("Options:")
    print("  compile                    Just compile, don't run")
    print("  manual                     Use manual input instead of input.txt")
    print("  -i <file>                  Use specific input file")
    print()
    print("Examples:")
    print("  python run.py 50 A                    # Use problems/50/input.txt (default)")
    print("  python run.py 50 A manual             # Manual input via terminal")
    print("  python run.py 50 A compile            # Just compile")
    print("  python run.py 50 A -i test.txt        # Use specific input file")
    print()
    print("Default behavior:")
    print("  Automatically uses problems/<contest>/input.txt if it exists")

def main():
    if len(sys.argv) < 3:
        show_help()
        sys.exit(1)
    
    contest = sys.argv[1]
    problem = sys.argv[2].upper()
    
    # Parse options
    compile_only = False
    manual_input = False
    input_file = None
    
    i = 3
    while i < len(sys.argv):
        arg = sys.argv[i]
        if arg.lower() == "compile":
            compile_only = True
        elif arg.lower() == "manual":
            manual_input = True
        elif arg == "-i" and i + 1 < len(sys.argv):
            input_file = sys.argv[i + 1]
            i += 1  # Skip the next argument
        i += 1
    
    compile_and_run(contest, problem, compile_only, manual_input, input_file)

if __name__ == "__main__":
    main() 