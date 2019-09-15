import { Injectable } from '@angular/core';
import { Problem } from 'src/model/Problem';
import { BehaviorSubject } from 'rxjs';
@Injectable({
  providedIn: 'root',
})
export class ProblemService {
  problem = new BehaviorSubject({});

  constructor() {}

  getProblem() {
    return this.problem;
  }

  setProblem(p: Problem) {
    return this.problem.next(p);
  }
  unsetProblem() {
    return this.problem.next(null);
  }
}
