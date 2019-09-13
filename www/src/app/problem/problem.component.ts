import { Component, OnInit } from '@angular/core';
import { Problem } from '../../../../algorithm.T/src/model/Problem';
import { ProblemService } from '../problem.service';

@Component({
  selector: 'app-problem',
  templateUrl: './problem.component.html',
  styleUrls: ['./problem.component.scss'],
})
export class ProblemComponent implements OnInit {
  problem: Problem;
  constructor(private problemService: ProblemService) {}

  ngOnInit() {
    this.problemService.getProblem().subscribe((p: Problem) => (this.problem = p));
  }
}
