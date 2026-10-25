import multiprocessing
import sys

def burn_core():
    """Infinite loop of heavy arithmetic to stress the CPU."""
    while True:
        # Exponentiation of large numbers forces maximum CPU cycle usage
        _ = 9999 ** 9999

if __name__ == '__main__':
    # Detect the number of logical CPU cores
    cores = multiprocessing.cpu_count()
    print(f"🔥 EXTREME CPU STRESS TEST INITIALIZED 🔥")
    print(f"Targeting all {cores} logical cores at 100% load.")
    print("Press Ctrl+C to abort the test...\n")
    
    processes = []
    
    # Spawn a dedicated worker process for every core
    for i in range(cores):
        p = multiprocessing.Process(target=burn_core)
        processes.append(p)
        p.start()
        
    try:
        # Keep the main thread alive while workers burn the CPU
        for p in processes:
            p.join()
    except KeyboardInterrupt:
        print("\n🛑 Test Aborted by user. Cooling down...")
        for p in processes:
            p.terminate()
            p.join()
        sys.exit(0)