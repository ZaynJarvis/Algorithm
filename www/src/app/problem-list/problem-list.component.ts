import { Component, OnInit } from '@angular/core';
import { AngularFirestore } from '@angular/fire/firestore';
import { Problem } from '../../../src/model/Problem';
import { ProblemService } from '../problem.service';
@Component({
  selector: 'app-problem-list',
  templateUrl: './problem-list.component.html',
  styleUrls: ['./problem-list.component.scss'],
})
export class ProblemListComponent implements OnInit {
  problems: Problem[];
  selected: number;
  constructor(private db: AngularFirestore, private problemService: ProblemService) {}

  ngOnInit() {
    const problemService = this.db.collection('problem').valueChanges();
    problemService.subscribe((p: Problem[]) => {
      this.problems = p;
      if (this.problems.length > 0) {
        this.problemService.setProblem(this.problems[0]);
      }
      this.selected = 0;
    });
  }

  onClick(p: Problem, i: number) {
    this.problemService.setProblem(p);
    this.selected = i;
  }
}
