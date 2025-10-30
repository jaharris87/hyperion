import argparse

parser = argparse.ArgumentParser(
                    prog="setup.py",
                    description="HYPERION Setup",
                    epilog="")

known_setups = ["pectest", "serial", "simd"]
known_networks = [16, 150, 365]

parser.add_argument("-b", "--build", nargs=1, choices=known_setups,
                    required=True, help="build specified test")

parser.add_argument("-s", "--size", nargs=1, type=int, choices=known_networks,
                    required=True, help="specify number of isotopes in network")

args = parser.parse_args()

import sys
sys.path.insert(0, "build/setup")
import setup_eval as seval

seval.build(args.build[0], args.size[0])
