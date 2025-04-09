import json
import os

TESTS_TO_POINTS_MAP = {
    "SingleWordInputs" : 15,
    "AllStringsOdd" : 7,
    "OneStringEven" : 8,
    "EmptyListLinkedList" : 2,
    "SingleValueInsertAfter" :2,
    "SingleValueInsertBefore" : 2,
    "MultiValueInsertMiddle" : 3,
    "MultiValueInsertFirst" : 3,
    "MultiValueInsertEnd" : 3,
    "EmptyListChangeAmount" : 7,
    "SingleCoin" : 10,
    "SingleSolution" : 13,
    "MulipleSolutions" : 15,
}

def generate_gradescope_results(input_file, top_level_results, problem_number) -> int:
    # Load Googletest JSON report
    with open(input_file, "r") as f:
        gtest_report = json.load(f)

    if "error" in gtest_report:
        top_level_results["tests"].append(
            {
                "name": f"Failure on problem {problem_number}",
                "output": gtest_report.get("output", "failure"),
                "visibility": "visible"
            }
        )
        return 0

    # Parse each test case
    total_score = 0.0
    for suite in gtest_report.get("testsuites", []):
        for test in suite.get("testsuite", []):
            test_name = test.get("name", "Unnamed Test")
            status = test.get("status", "FAILED")

            failures = test.get("failures", [])

            earned_points = TESTS_TO_POINTS_MAP[test_name] if status == "RUN" and len(failures) == 0 else 0.0
            test_output = test.get("output", "Test passed.") if len(failures) == 0 else " ".join([d["failure"] for d in failures])

            # Add test case result
            top_level_results["tests"].append({
                "suite": suite.get("name", "Default Suite"),
                "name": test_name,
                "score": earned_points,
                "max_score": TESTS_TO_POINTS_MAP[test_name],
                "output": test_output,
                "visibility": "hidden"
            })

            total_score += earned_points

    # Calculate overall score
    return total_score

def process_problem(problem_number: int, total_score: int, gradescope_results: dict) -> int:
    """Checks if a problem's report file exists and updates the total score."""
    input_file = f"submission/report{problem_number}.json"

    if os.path.exists(input_file):
        return total_score + generate_gradescope_results(input_file, gradescope_results, problem_number)
    else:
        print(f"Output for problem {problem_number} not found")
        return total_score

if __name__ == "__main__":
    # Initialize Gradescope results structure
    gradescope_results = {
        "score": 0.0,
        "visibility": "visible",
        "stdout_visibility": "hidden",
        "execution_time": 0.0,
        "output": "Test results from Googletest.",
        "tests": []
    }

    output_file = "results/results.json"
    total_score = 0.0

    total_score = process_problem(1, total_score, gradescope_results)
    total_score = process_problem(2, total_score, gradescope_results)
    total_score = process_problem(3, total_score, gradescope_results)
    total_score = process_problem(5, total_score, gradescope_results)

    gradescope_results["score"] = total_score

    overall_output = "Not all tests passing, please come to office hours and lab for any help!!" if total_score != 90.0 else "All tests passed!  Great work!"
    gradescope_results["tests"].append({
        "name": "Overall Tests",
        "output": overall_output,
        "visibility": "visible"
    })

    # Write to Gradescope results.json
    with open(output_file, "w") as f:
        json.dump(gradescope_results, f, indent=4)
