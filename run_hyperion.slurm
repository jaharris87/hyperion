#!/bin/bash
#SBATCH -A ast218                     # Project allocation
#SBATCH -J hyperion_parallel_150      # Job name
#SBATCH -o %x-%j.out                  # Output file
#SBATCH -t 00:30:00                   # Walltime
#SBATCH -p batch                      # Batch queue
#SBATCH -N 1                          # One node
#SBATCH -n 1                          # One MPI task
#SBATCH -c 1                          # One CPU core
#SBATCH --gres=gpu:1                  # <-- You MUST request a GPU
#SBATCH --exclusive                   # Optional: full node for debugging

### Load environment needed for HIP builds
module purge                           # <-- ALWAYS purge first on Frontier

module load PrgEnv-amd                 # AMD compiler environment
module load rocm/6.2.4                 # HIP/ROCm
module load craype-accel-amd-gfx90a    # Correct GPU target
module load hdf5/1.14.5-mpi            # HDF5 if needed


# Navigate to your working directory
cd $SLURM_SUBMIT_DIR

# Print some diagnostic info
echo "Running on host $(hostname)"
echo "Current working directory: $(pwd)"
echo "Job started at: $(date)"

# Print full GPU and environment report
#echo "------ ROCMINFO ------"
#srun rocminfo

#echo "------ HIPCONFIG ------"
#srun hipconfig

# Run the executable
srun ./object/gpu_test

echo "Job finished at: $(date)"
