import testmod_physical as testphys

if __name__ == "__main__":
    print("Running HYPERION test.")
    failures = 0
    failures = failures + testphys.run()
    if failures == 0:
        print("Test complete, no failures found.")
    else:
        print(f"Test complete, {failures} failure(s) found.")
